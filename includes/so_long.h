/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:56:49 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:48 by gcampos-         ###   ########.fr       */
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

// This struct will be used to store the game images
typedef struct s_game_imgs
{
	void	*img_p;
	void	*img_c;
	void	*img_e;
	void	*img_w;
	void	*img_bg;
}	t_game_imgs;

// This struct will be used to store the game
typedef struct s_game
{
	int i;
	int j;
	int	map_height;
	int	map_width;
	int	c_count;
	int	e_count;
	int	p_count;
	int	player_x;
	int	player_y;
	int	count_moves;

	char	**map;
	char	*file_location;
	
	void	*mlx_ptr;
	void	*win_ptr;
	
	t_game_imgs		*imgs;
}	t_game;

// clean.c
void	clean_map(char **map);
void	clean_imgs(t_game *game);
void	clean_display(t_game *game);

// create_map.c
void	map_create(t_game *game);
void	read_map(t_game	*game);

// graphics.c
void	init_mlx(t_game *game);

// parsing.c
int	game_counters(t_game *game);
int	check_wall(t_game *game);
int	check_tiles(t_game *game);
int	check_path(t_game *game);
void	check_map(t_game *game);

// utils.c
int	flood_fill(char **game, size_t x, size_t y);
void	filename(t_game *game, char *file);
int	exit_error(t_game *game, char *msg);

#endif