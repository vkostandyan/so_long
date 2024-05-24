/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:39 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/24 22:02:47 by vkostand         ###   ########.fr       */
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
    int line_len;
    t_counter counter;
}       t_so_long;        
      
//--------------------- Map -------------------------
t_so_long    init_map();

//--------------------- Validation -------------------------
void    parse(int argc, char **argv, t_so_long *so_long);
void    check_name(char *av);
int	    char_match(char c, char const *str);

//--------------------- Error -------------------------
void	send_error(char *str);

//--------------------- Free -------------------------
void	free_matrix(char **str);

#endif