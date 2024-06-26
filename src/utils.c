/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:45:33 by gcampos-          #+#    #+#             */
/*   Updated: 2024/06/19 15:57:55 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit(t_game *game)
{
	game->map[game->p_x][game->p_y] = EXIT;
	game->on_exit = 0;
}

int	flood_fill(char **game, size_t x, size_t y)
{
	static int	count = 0;

	if (game[x][y] == WALL)
		return (0);
	if (game[x][y] == EXIT)
		count++;
	game[x][y] = WALL;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	return (count == 1);
}

void	filename(t_game *game, char *file)
{
	size_t	i;

	i = ft_strlen(file);
	game->file_location = ft_strdup(file);
	if (!game->file_location)
		exit_error(NULL, "strjoin failed\n");
	if (access(game->file_location, F_OK))
		exit_error(game, "No exist map\n");
	if (access(game->file_location, R_OK))
		exit_error(game, "Permission denied\n");
	if (!ft_strnstr(file + i - 4, ".ber", 4))
		exit_error(game, "Bad extension\n");
}

int	exit_error(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	clean_display(game);
	exit(EXIT_FAILURE);
}
