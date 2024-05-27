/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:39 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/27 15:59:19 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"

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

typedef struct s_counter
{
    int player;
    int enemy;
    int exit;
    int coin;
    int wall;
    int empty_space;
}       t_counter;  

typedef struct s_so_long
{
    char **map;
    int line;
    int column;
    t_counter counter;
}       t_so_long;        
      
//--------------------- Map -------------------------
t_so_long    init_map();

//--------------------- Validation -------------------------
void    parse(int argc, char **argv, t_so_long *so_long);
void    check_name(int argc, char **argv);
int	    char_match(char c, char const *str);
int     is_empty_line(char *str, char *set);
char	*ft_join(char const *s1, char const *s2);
char	*ft_trim(char const *s1, char const *set);

//--------------------- Error -------------------------
void	send_error(char *str);

//--------------------- Free -------------------------
void	free_matrix(char **str);

#endif