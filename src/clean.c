/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:01:59 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/14 15:24:20 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(char **map)
{
	int i;

	i = -1;
	if (!map)
		return ;		
	while (map[++i])
		free (map[i]);
	free(map);
}

void	clean_imgs(t_game *game)
{
	if (game->imgs)
	{
		mlx_destroy_image(game->mlx_ptr, game->imgs->img_p);
		mlx_destroy_image(game->mlx_ptr, game->imgs->img_c);
		mlx_destroy_image(game->mlx_ptr, game->imgs->img_e);
		mlx_destroy_image(game->mlx_ptr, game->imgs->img_w);
		mlx_destroy_image(game->mlx_ptr, game->imgs->img_bg);
		free(game->imgs);
	}
}

void	clean_display(t_game *game)
{
	if (!game)
		return ;
	if (game->imgs)
		clean_imgs(game);
	if (game->map)
		clean_map(game->map);
	free (game->file_location);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(EXIT_SUCCESS);
}
