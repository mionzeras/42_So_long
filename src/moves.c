/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:56:59 by gcampos-          #+#    #+#             */
/*   Updated: 2024/06/06 17:46:10 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	if (game->map[game->p_x - 1][game->p_y] != WALL && game->on_exit == 0)
	{
		if (game->map[game->p_x - 1][game->p_y] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->p_x - 1][game->p_y] == EXIT && game->c_count != 0)
			game->on_exit = 1;
		game->map[game->p_x][game->p_y] = EMPTY;
	}
	else if (game->map[game->p_x - 1][game->p_y] != WALL && game->on_exit == 1)
		move_exit(game);
	if (game->map[game->p_x - 1][game->p_y] == COLLECTIBLE)
		game->c_count--;
	if (game->map[game->p_x - 1][game->p_y] != WALL)
	{
		game->p_x--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	game->map[game->p_x][game->p_y] = PLAYER;
	render_map(game);
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[game->p_x + 1][game->p_y] != WALL && game->on_exit == 0)
	{
		if (game->map[game->p_x + 1][game->p_y] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->p_x + 1][game->p_y] == EXIT && game->c_count != 0)
			game->on_exit = 1;
		game->map[game->p_x][game->p_y] = EMPTY;
	}
	else if (game->map[game->p_x + 1][game->p_y] != WALL && game->on_exit == 1)
		move_exit(game);
	if (game->map[game->p_x + 1][game->p_y] == COLLECTIBLE)
		game->c_count--;
	if (game->map[game->p_x + 1][game->p_y] != WALL)
	{
		game->p_x++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	game->map[game->p_x][game->p_y] = PLAYER;
	render_map(game);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map[game->p_x][game->p_y - 1] != WALL && game->on_exit == 0)
	{
		if (game->map[game->p_x][game->p_y - 1] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->p_x][game->p_y - 1] == EXIT && game->c_count != 0)
			game->on_exit = 1;
		game->map[game->p_x][game->p_y] = EMPTY;
	}
	else if (game->map[game->p_x][game->p_y - 1] != WALL && game->on_exit == 1)
		move_exit(game);
	if (game->map[game->p_x][game->p_y - 1] == COLLECTIBLE)
		game->c_count--;
	if (game->map[game->p_x][game->p_y - 1] != WALL)
	{
		game->p_y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	game->map[game->p_x][game->p_y] = PLAYER;
	render_map(game);
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map[game->p_x][game->p_y + 1] != WALL && game->on_exit == 0)
	{
		if (game->map[game->p_x][game->p_y + 1] == EXIT && game->c_count == 0)
		{
			ft_printf("YOU WIN!\n");
			quit_game(game);
		}
		if (game->map[game->p_x][game->p_y + 1] == EXIT && game->c_count != 0)
			game->on_exit = 1;
		game->map[game->p_x][game->p_y] = EMPTY;
	}
	else if (game->map[game->p_x][game->p_y + 1] != WALL && game->on_exit == 1)
		move_exit(game);
	if (game->map[game->p_x][game->p_y + 1] == COLLECTIBLE)
		game->c_count--;
	if (game->map[game->p_x][game->p_y + 1] != WALL)
	{
		game->p_y++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	game->map[game->p_x][game->p_y] = PLAYER;
	render_map(game);
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
