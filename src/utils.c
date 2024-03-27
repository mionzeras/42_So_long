/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:45:33 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/06 20:19:19 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int 	fd;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file extension\n");
	if (!ft_strnstr(file + i - 4, ".ber", 4))
		exit_error(NULL, "File must have .ber extension\n");
	game->file_location = ft_strjoin("map/", file);
	if (!game->file_location)
		exit_error(NULL, "strjoin failed\n");
	fd = open(game->file_location, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, "File not found\n");
	close(fd);
}

int	exit_error(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	clean_display(game);
	exit(EXIT_FAILURE);
}
