/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:39 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/12 20:29:32 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"

# define ARG_ERR "Invalid number of arguments\n"
# define FILE_NAME_ERR "Invalid file name\n"
# define FILE_OPEN_ERR "Can't open file\n"
# define CHAR_ERR "Invalid char in the map\n"
# define COIN_ERR "Map must contain at least 1 coin\n"
# define PLAYER_ERR "Map must contain 1 player\n"
# define EXIT_ERR "Map must contain 1 exit\n"
# define FD_ERR "Map must contain 1 exit\n"
# define EMPTY_LINE_ERR "Map must not have empty spaces\n"
# define RECTANGLE_ERR "Map must be rectangular\n"
# define WALL_ERR "Map must be surrounded by walls\n"
# define MALLOC_ERR "Memory allocation failed\n"

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

typedef struct s_so_long
{
	char		**map;
	int			line;
	int			column;
	t_point		map_size;
	t_point		player_position;
	t_counter	counter;
}				t_so_long;

//--------------------- Map -------------------------
t_so_long		init_map(void);

//--------------------- Validation -------------------------
void			parse(int argc, char **argv, t_so_long *so_long);
void			check_name(int argc, char **argv);
int				char_match(char c, char const *str);
char			*ft_join(char const *s1, char const *s2);
char			*ft_trim(char const *s1, char const *set);
void			find_player_position(t_so_long *so_long);
void			ft_flood_fill(char **map, int line, int column);
char			*ft_strcpy(char *dest, char *src);
void			check_map_is_playable(t_so_long *so_long);

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