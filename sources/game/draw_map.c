/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:42:03 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 16:09:05 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_so_long *so_long, int i, int j, char c)
{
	if (c == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->wall,
			SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->empty,
			SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->exit,
			SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->collectible, SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			SQUARE_SIZE * j, SQUARE_SIZE * i);
}

void	draw_map(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			put_image_to_window(so_long, i, j, so_long->map[i][j]);
			j++;
		}
		i++;
	}
}
