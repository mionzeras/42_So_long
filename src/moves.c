/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:56:59 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/29 00:11:57 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != WALL)
	{
		if (game->map[game->player_y - 1][game->player_x] == COLLECTIBLE)
			game->c_count--;
		if (game->map[game->player_y - 1][game->player_x] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->player_y - 1][game->player_x] == EXIT && game->c_count != 0)
			return (0);
		game->map[game->player_y][game->player_x] = EMPTY;
		game->player_y--;
		game->map[game->player_y][game->player_x] = PLAYER;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != WALL)
	{
		if (game->map[game->player_y + 1][game->player_x] == COLLECTIBLE)
			game->c_count--;
		if (game->map[game->player_y + 1][game->player_x] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->player_y + 1][game->player_x] == EXIT && game->c_count != 0)
			return (0);
		game->map[game->player_y][game->player_x] = EMPTY;
		game->player_y++;
		game->map[game->player_y][game->player_x] = PLAYER;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != WALL)
	{
		if (game->map[game->player_y][game->player_x - 1] == COLLECTIBLE)
			game->c_count--;
		if (game->map[game->player_y][game->player_x - 1] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->player_y][game->player_x - 1] == EXIT && game->c_count != 0)
			return (0);
		game->map[game->player_y][game->player_x] = EMPTY;
		game->player_x--;
		game->map[game->player_y][game->player_x] = PLAYER;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != WALL)
	{
		if (game->map[game->player_y][game->player_x + 1] == COLLECTIBLE)
			game->c_count--;
		if (game->map[game->player_y][game->player_x + 1] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->player_y][game->player_x + 1] == EXIT && game->c_count != 0)
			return (0);
		game->map[game->player_y][game->player_x] = EMPTY;
		game->player_x++;
		game->map[game->player_y][game->player_x] = PLAYER;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
	return (0);
}

int	check_key(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		move_up(game);
	else if (key == A || key == LEFT)
		move_left(game);
	else if (key == S || key == DOWN)
		move_down(game);
	else if (key == D || key == RIGHT)
		move_right(game);
	return (0);
}