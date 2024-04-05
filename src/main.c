/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:52:26 by gcampos-          #+#    #+#             */
/*   Updated: 2024/04/05 18:13:16 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	filename(&game, file);
	read_map(&game);
	map_create(&game);
	check_map(&game);
	init_mlx(&game);
	load_images(&game);
	render_map(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, check_key, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, quit_game, &game);
	mlx_loop(game.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments\n");
	init_game(av[1]);
	return (0);
}
