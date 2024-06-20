/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:29:19 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 16:08:27 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_so_long *so_long)
{
	t_point	c;

	so_long->player = mlx_xpm_file_to_image(so_long->mlx, PLAYER_PATH,
			&c.column, &c.line);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, WALL_PATH, &c.column,
			&c.line);
	so_long->empty = mlx_xpm_file_to_image(so_long->mlx, EMPTY_PATH, &c.column,
			&c.line);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, EXIT_PATH, &c.column,
			&c.line);
	so_long->collectible = mlx_xpm_file_to_image(so_long->mlx, COLLECTIBLE_PATH,
			&c.column, &c.line);
	so_long->enemy.enemy1 = mlx_xpm_file_to_image(so_long->mlx, ENEMY1_PATH,
			&c.column, &c.line);
	so_long->enemy.enemy2 = mlx_xpm_file_to_image(so_long->mlx, ENEMY2_PATH,
			&c.column, &c.line);
	so_long->enemy.enemy3 = mlx_xpm_file_to_image(so_long->mlx, ENEMY3_PATH,
			&c.column, &c.line);
	so_long->enemy.enemy4 = mlx_xpm_file_to_image(so_long->mlx, ENEMY4_PATH,
			&c.column, &c.line);
}
