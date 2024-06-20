/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:27 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:28:22 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_so_long *so_long)
{
	so_long->counter.player = 0;
	so_long->counter.enemy = 0;
	so_long->counter.exit = 0;
	so_long->counter.coin = 0;
	so_long->counter.wall = 0;
	so_long->counter.wall = 0;
	so_long->line = 0;
	so_long->column = 0;
	so_long->step = 0;
}

static void	game(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, so_long->map_size.column
			* SQUARE_SIZE, so_long->map_size.line * SQUARE_SIZE, "so_long");
	init_images(so_long);
	draw_map(so_long);
	mlx_loop_hook(so_long->mlx, enemy_animation, so_long);
	mlx_string_put(so_long->mlx, so_long->window, 0, 0, 0XFFFFFF, "Steps: 0");
	mlx_key_hook(so_long->window, close_window, so_long);
	mlx_hook(so_long->window, 2, 1, movement, so_long);
	mlx_hook(so_long->window, 17, 0, end_game, so_long);
	mlx_loop(so_long->mlx);
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	init_struct(&so_long);
	parse(argc, argv, &so_long);
	game(&so_long);
	return (0);
}
