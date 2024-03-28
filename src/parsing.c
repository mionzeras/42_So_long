/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:10:28 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/28 23:35:59 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_counters(t_game *game)
{
	if (game->p_count != 1 || game->e_count != 1 || game->c_count == 0)
		exit_error(game, "Invalid map\n");
	return (1);
}

int	check_wall(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
	{
		if (game->map[i][0] != WALL || game->map[i][game->map_width - 1] != WALL)
			return (0);
	}
	i = -1;
	while (++i < game->map_width)
	{
		if (game->map[0][i] != WALL || game->map[game->map_height - 1][i] != WALL)
			return (0);
	}
	return (1);
}
int	check_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_x = i;
				game->player_y = j;
				game->p_count++;
			}
			else if (game->map[i][j] == EXIT)
				game->e_count++;
			else if (game->map[i][j] == COLLECTIBLE)
				game->c_count++;
			if (!ft_strchr("01CEP", game->map[i][j]))
				return (0);
		}
	}
	game_counters(game);
	return (1);
}

int	check_path(t_game *game)
{
	int	i;
	int	reached;
	char	**path;

	i = -1;
	reached = 0;
	path = calloc(game->map_height + 1, sizeof(char *));
	if (!path)
		exit_error(game, "Memory allocation failed\n");
	while (++i < game->map_height)
	{
		path[i] = ft_strdup(game->map[i]);
		if (!path[i])
		{
			clean_map(path);
			exit_error(game, "Memory allocation failed\n");
		}
	}
	reached = flood_fill(path, game->player_x, game->player_y);
	clean_map(path);
	return (reached);
}

void	check_map(t_game *game)
{
	if (!game->map_height)
		exit_error(game, "Map is empty\n");
	if (!check_tiles(game))
		exit_error(game, "Map has invalid tiles\n");
	if (!check_wall(game))
		exit_error(game, "Map is not surrounded by walls\n");
	if (!check_path(game))
		exit_error(game, "Cannot reach the exit\n");
}
