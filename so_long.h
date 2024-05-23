/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:39 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/23 21:29:30 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdio.h>

# define ARG_ERR "Invalid number of arguments\n"
# define FILE_NAME_ERR "Invalid file name\n" 
# define FILE_OPEN_ERR "Can't open file\n"

typedef struct s_so_long
{
    char **map;
    int line;
    int line_len;
    int fd;
}       t_so_long;        
      
//--------------------- Map -------------------------
t_so_long    init_map();

//--------------------- Validation -------------------------
void    parse(int argc, char **argv);
void    check_name(char *av);

//--------------------- Error -------------------------
void	send_error(char *str);

#endif