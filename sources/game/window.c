/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:50:36 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:28:14 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_so_long *so_long)
{
	free_matrix(so_long->map);
	mlx_destroy_image(so_long->mlx, so_long->empty);
	mlx_destroy_image(so_long->mlx, so_long->wall);
	mlx_destroy_image(so_long->mlx, so_long->collectible);
	mlx_destroy_image(so_long->mlx, so_long->enemy.enemy1);
	mlx_destroy_image(so_long->mlx, so_long->enemy.enemy2);
	mlx_destroy_image(so_long->mlx, so_long->enemy.enemy3);
	mlx_destroy_image(so_long->mlx, so_long->enemy.enemy4);
	mlx_destroy_image(so_long->mlx, so_long->player);
	mlx_destroy_image(so_long->mlx, so_long->exit);
	mlx_clear_window(so_long->mlx, so_long->window);
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit(0);
}

int	close_window(int keycode, t_so_long *so_long)
{
	if (keycode == KEY_ESC)
		end_game(so_long);
	return (0);
}

void	draw_window(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, so_long->map_size.column
			* SQUARE_SIZE, so_long->map_size.line * SQUARE_SIZE, "so_long");
	mlx_key_hook(so_long->window, close_window, so_long);
	mlx_hook(so_long->window, 17, 1, end_game, so_long);
	init_images(so_long);
	draw_map(so_long);
	mlx_loop(so_long->mlx);
}
