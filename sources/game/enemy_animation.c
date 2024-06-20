/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:19 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 16:08:44 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_enemy_to_window(t_so_long *so_long, int i, int j, int c)
{
	if (c == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->enemy.enemy1, SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 2)
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->enemy.enemy2, SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 3)
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->enemy.enemy3, SQUARE_SIZE * j, SQUARE_SIZE * i);
	else if (c == 4)
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->enemy.enemy4, SQUARE_SIZE * j, SQUARE_SIZE * i);
}

static void	draw_enemy(t_so_long *so_long, int i, int j)
{
	static int	speed;

	if (speed < 50)
		put_enemy_to_window(so_long, i, j, 1);
	else if (speed < 100)
		put_enemy_to_window(so_long, i, j, 2);
	else if (speed < 150)
		put_enemy_to_window(so_long, i, j, 3);
	else if (speed < 200)
		put_enemy_to_window(so_long, i, j, 4);
	else
		speed = 0;
	speed++;
}

int	enemy_animation(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'X')
				draw_enemy(so_long, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
