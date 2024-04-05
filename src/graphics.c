/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:51 by gcampos-          #+#    #+#             */
/*   Updated: 2024/04/05 18:12:31 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error(game, "Error initializing mlx\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
			game->map_width * SIZE, game->map_height * SIZE, "so_long");
	if (!game->win_ptr)
		exit_error(game, "Error creating window\n");
}

void	load_images(t_game *game)
{
	int	i;
	int	j;

	i = SIZE;
	j = SIZE;
	game->img_0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/0.xpm", &i, &j);
	game->img_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/1.xpm", &i, &j);
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/C.xpm", &i, &j);
	game->img_p = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/P.xpm", &i, &j);
	game->img_w = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/W.xpm", &i, &j);
}

void	render_tiles(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->img_w, x * SIZE, y * SIZE);
	else if (game->map[y][x] == EMPTY)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->img_0, x * SIZE, y * SIZE);
	else if (game->map[y][x] == PLAYER)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->img_p, x * SIZE, y * SIZE);
	else if (game->map[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->img_c, x * SIZE, y * SIZE);
	else if (game->map[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->img_1, x * SIZE, y * SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
			render_tiles(game, x, y);
	}
}
