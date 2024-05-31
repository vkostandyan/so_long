/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:32:56 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/31 21:41:02 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.line < 0 || cur.line >= size.line || cur.column < 0 || cur.column >= size.column)
    {
        // printf("1\n");
		return;
    }
    if (ft_strchr("ECP", tab[cur.line][cur.column]))
		tab[cur.line][cur.column] = '0';
    if (tab[cur.line][cur.column] != to_fill)
    {
        // printf("2\n");
	    return ; 
    }
	tab[cur.line][cur.column] = 'F';
	flood_fill(tab, size, (t_point){cur.column - 1, cur.line}, to_fill);
	flood_fill(tab, size, (t_point){cur.column + 1, cur.line}, to_fill);
	flood_fill(tab, size, (t_point){cur.column, cur.line - 1}, to_fill);
	flood_fill(tab, size, (t_point){cur.column, cur.line + 1}, to_fill);
}