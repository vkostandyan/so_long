/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:39 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:26:37 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>

# define ARG_ERR "\033[1;31mInvalid number of arguments\033[0m\n"
# define FILE_NAME_ERR "\033[1;31mInvalid file name\033[0m\n"
# define FILE_OPEN_ERR "\033[1;31mCan't open file\033[0m\n"
# define CHAR_ERR "\033[1;31mInvalid char in the map\033[0m\n"
# define COIN_ERR "\033[1;31mMap must contain at least 1 coin\033[0m\n"
# define PLAYER_ERR "\033[1;31mMap must contain 1 player\033[0m\n"
# define EXIT_ERR "\033[1;31mMap must contain 1 exit\033[0m\n"
# define FD_ERR "\033[1;31mMap must contain 1 exit\033[0m\n"
# define EMPTY_LINE_ERR "\033[1;31mMap must not have empty spaces\033[0m\n"
# define RECTANGLE_ERR "\033[1;31mMap must be rectangular\033[0m\n"
# define WALL_ERR "\033[1;31mMap must be surrounded by walls\033[0m\n"
# define MALLOC_ERR "\033[1;31mMemory allocation failed\033[0m\n"
# define SIZE_ERR "\033[1;31mMap is larger than screen\033[0m\n"

# define WALL_PATH "./images/wall.xpm"
# define PLAYER_PATH "./images/player.xpm"
# define EMPTY_PATH "./images/empty.xpm"
# define COLLECTIBLE_PATH "./images/collectible.xpm"
# define EXIT_PATH "./images/exit.xpm"
# define ENEMY1_PATH "./images/enemy1.xpm"
# define ENEMY2_PATH "./images/enemy2.xpm"
# define ENEMY3_PATH "./images/enemy3.xpm"
# define ENEMY4_PATH "./images/enemy4.xpm"

# define SQUARE_SIZE 32
# define KEY_ESC 53
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define DOWN_KEY 1
# define UP_KEY 13

typedef struct s_point
{
	int			line;
	int			column;
}				t_point;

typedef struct s_counter
{
	int			player;
	int			enemy;
	int			exit;
	int			coin;
	int			wall;
	int			empty_space;
}				t_counter;

typedef struct s_enemy
{
	void		*enemy1;
	void		*enemy2;
	void		*enemy3;
	void		*enemy4;
}				t_enemy;

typedef struct s_so_long
{
	char		**map;
	int			line;
	int			column;
	t_point		map_size;
	t_point		player_position;
	t_counter	counter;
	void		*mlx;
	void		*window;
	void		*player;
	void		*wall;
	void		*empty;
	void		*collectible;
	void		*exit;
	t_enemy		enemy;
	int			step;
}				t_so_long;

//--------------------- Map -------------------------
// t_so_long		init_map(void);
void			draw_window(t_so_long *so_long);
void			init_images(t_so_long *so_long);
void			draw_map(t_so_long *so_long);
void			put_image_to_window(t_so_long *so_long, int i, int j, char c);
int				end_game(t_so_long *so_long);
void			move_to(t_so_long *so_long, int line, int column,
					char direction);
int				movement(int keycode, t_so_long *so_long);
int				close_window(int keycode, t_so_long *so_long);
void			change_player_position(t_so_long *so_long, char direction);
int				enemy_animation(t_so_long *so_long);

//--------------------- Validation -------------------------
void			parse(int argc, char **argv, t_so_long *so_long);
int				char_match(char c, char const *str);
char			*ft_join(char const *s1, char const *s2);
char			*ft_trim(char const *s1, char const *set);
char			*ft_strcpy(char *dest, char *src);
void			check_map_is_playable(t_so_long *so_long);
void			check_size(t_so_long *so_long);

//--------------------- Validation utils -------------------------
int				line_contains_spaces(char *str, char *set);
int				is_empty_line(char *str, char *set);
char			*read_map(int fd);
void			check_chars(char *str, t_so_long *so_long);
char			*check_chars_quantity(t_so_long *so_long);

//--------------------- Error -------------------------
void			send_error(char *str);

//--------------------- Free -------------------------
void			free_matrix(char **str);

#endif