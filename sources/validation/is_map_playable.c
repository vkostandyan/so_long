/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_playable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:25:50 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/31 21:50:20 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player_position(t_so_long *so_long)
{
    int i;
    int j;
    
    i = 1;
    while (so_long->map[i])
    {
        j = 1;
        while (so_long->map[i][j])
        {
            if (so_long->map[i][j] == 'P')
            {
                so_long->player_position.column = j;
                so_long->player_position.line = i;   
                return ;
            }
            j++;
        }
        i++;
    }
}

static char **copy_map(t_so_long *so_long)
{
    char **copy;
    int i;

    copy = (char **)malloc(sizeof(char *) * (so_long->map_size.line + 1));
    if (!copy)
    {
        free_matrix(so_long->map);
        send_error(MALLOC_ERR);
    }
    copy[so_long->map_size.line] = NULL;
    i = 0;
    while (i < so_long->map_size.line)
    {
        copy[i] = (char *)malloc(sizeof(char) * (so_long->map_size.column + 1));
        if (!copy[i])
        {
        free_matrix(so_long->map);
        free_matrix(copy);
        send_error(MALLOC_ERR);
        }
        ft_strcpy(copy[i], so_long->map[i]);
        i++;
    }   
    return (copy); 
}

void map_is_playable(char **str, t_so_long *so_long)
{
    int i;
    int j;

    i = 1;
    while (str[i])
    {
        j = 1;
        while (str[i][j])
        {
            if (ft_strchr("EC", str[i][j]))
            {
                free_matrix(so_long->map);
                free_matrix(str);
                send_error("Invalid path\n");
            }
            j++;
        }
        i++;
    }
}

void check_map_is_playable(t_so_long *so_long)
{
    char **copy;
    
    find_player_position(so_long);
    printf("line %d\ncolumn %d\n", so_long->player_position.line, so_long->player_position.column);
    copy = copy_map(so_long);
    flood_fill(copy, so_long->map_size, so_long->player_position, '0');
    map_is_playable(copy, so_long);
    int i = 0;
    while (copy[i])
    {
        printf("%s\n", copy[i]);
        i++;
    }
    free_matrix(copy);
}
