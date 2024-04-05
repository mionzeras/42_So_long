/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:56:49 by gcampos-          #+#    #+#             */
/*   Updated: 2024/04/05 18:06:14 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h" 
# include "../libft/libft.h"

// MACROS
# define SIZE			64
# define WALL			'1'
# define EMPTY			'0'
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'

//KEYWORDS
# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define LEFT	65361
# define DOWN	65364
# define RIGHT	65363

// This struct will be used to store the game
typedef struct s_game
{
	int		i;
	int		j;
	int		map_height;
	int		map_width;
	int		c_count;
	int		e_count;
	int		p_count;
	int		player_x;
	int		player_y;
	int		moves;

	char	**map;
	char	*file_location;

	void	*img_p;
	void	*img_c;
	void	*img_1;
	void	*img_w;
	void	*img_0;
	void	*mlx_ptr;
	void	*win_ptr;

}	t_game;

// clean.c
void	clean_map(char **map);
void	clean_imgs(t_game *game);
void	clean_display(t_game *game);
int		quit_game(t_game *game);

// create_map.c
void	map_create(t_game *game);
void	read_map(t_game	*game);

// graphics.c
void	init_mlx(t_game *game);
void	load_images(t_game *game);
void	render_tiles(t_game *game, int x, int y);
void	render_map(t_game *game);

// moves.c
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		check_key(int key, t_game *game);

// parsing.c
int		game_counters(t_game *game);
int		check_wall(t_game *game);
int		check_tiles(t_game *game);
int		check_path(t_game *game);
void	check_map(t_game *game);

// utils.c
int		lood_fill(char **game, size_t x, size_t y);
void	filename(t_game *game, char *file);
int		exit_error(t_game *game, char *msg);

#endif