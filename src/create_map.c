/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:19:58 by gcampos-          #+#    #+#             */
/*   Updated: 2024/06/05 19:10:29 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	line_size(t_game *game, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\0')
		i++;
	if (i != game->map_width)
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		exit_error(game, "No rectangular\n");
	}
}

void	map_create(t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	game->map = calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		exit_error(game, "Could not allocate memory\n");
	fd = open(game->file_location, O_RDONLY);
	while (++i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			free(line);
		line_size(game, line, fd);
		game->map[i] = ft_strtrim(line, "\n");
		if (!game->map[i])
			exit_error(game, "Could not copy map\n");
		free(line);
	}
	close(fd);
}

void	read_map(t_game	*game)
{
	int		fd;
	char	*line;

	game->i = 0;
	game->j = 0;
	fd = open(game->file_location, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		exit_error(game, "Empty map\n");
	}
	game->j = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		game->i++;
		line = get_next_line(fd);
	}
	game->map_height = game->i;
	game->map_width = game->j;
	close(fd);
}
