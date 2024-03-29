/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:01:59 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/28 23:45:07 by gcampos-         ###   ########.fr       */
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
	if (game->img_0 || game->img_1 || game->img_c || game->img_p || game->img_w)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_p);
		mlx_destroy_image(game->mlx_ptr, game->img_c);
		mlx_destroy_image(game->mlx_ptr, game->img_1);
		mlx_destroy_image(game->mlx_ptr, game->img_w);
		mlx_destroy_image(game->mlx_ptr, game->img_0);
	}
}

void	clean_display(t_game *game)
{
	if (!game)
		return ;
	clean_imgs(game);
	if (game->map)
		clean_map(game->map);
	free (game->file_location);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	quit_game(t_game *game)
{
	clean_display(game);
	exit(EXIT_SUCCESS);
}
