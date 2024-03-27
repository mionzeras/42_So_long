/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:51 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/14 19:48:51 by gcampos-         ###   ########.fr       */
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

	game->imgs->img_p = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/P.xpm", &i, &j);
	game->imgs->img_c = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/C.xpm", &i, &j);
	game->imgs->img_e = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/E.xpm", &i, &j);
	game->imgs->img_w = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/W.xpm", &i, &j);
	game->imgs->img_bg = mlx_xpm_file_to_image(game->mlx_ptr, \
			"textures/BG.xpm", &i, &j);
}