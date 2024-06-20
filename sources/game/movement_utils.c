/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:58:20 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 16:16:29 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_empty(t_so_long *so_long, int line, int column,
		char direction)
{
	int	x;
	int	y;

	x = so_long->player_position.line;
	y = so_long->player_position.column;
	put_image_to_window(so_long, line, column, 'P');
	if (so_long->map[x][y] == 'E')
		put_image_to_window(so_long, x, y, 'E');
	else
	{
		so_long->map[x][y] = '0';
		put_image_to_window(so_long, x, y, '0');
	}
	change_player_position(so_long, direction);
	so_long->step++;
}

static void	move_to_exit(t_so_long *so_long, int line, int column,
		char direction)
{
	int	x;
	int	y;

	x = so_long->player_position.line;
	y = so_long->player_position.column;
	if (so_long->counter.coin == 0)
	{
		write(1, "\033[1;32m", 7);
		write(1, "You Won!\n", 9);
		write(2, "\033[0m", 4);
		end_game(so_long);
	}
	so_long->map[x][y] = '0';
	put_image_to_window(so_long, line, column, 'P');
	put_image_to_window(so_long, x, y, '0');
	change_player_position(so_long, direction);
	so_long->step++;
}

static void	move_to_coin(t_so_long *so_long, int line, int column,
		char direction)
{
	int	x;
	int	y;

	x = so_long->player_position.line;
	y = so_long->player_position.column;
	put_image_to_window(so_long, line, column, 'P');
	if (so_long->map[x][y] == 'E')
		put_image_to_window(so_long, x, y, 'E');
	else
	{
		so_long->map[x][y] = '0';
		put_image_to_window(so_long, x, y, '0');
	}
	so_long->map[line][column] = '0';
	change_player_position(so_long, direction);
	so_long->step++;
	so_long->counter.coin--;
}

static void	move_to_enemy(t_so_long *so_long)
{
	write(2, "\033[1;31m", 7);
	write(1, "You Lost!\n", 10);
	write(2, "\033[0m", 4);
	end_game(so_long);
}

void	move_to(t_so_long *so_long, int line, int column, char direction)
{
	if (so_long->map[line][column] == 'E')
		move_to_exit(so_long, line, column, direction);
	else if (so_long->map[line][column] == '0')
		move_to_empty(so_long, line, column, direction);
	else if (so_long->map[line][column] == 'C')
		move_to_coin(so_long, line, column, direction);
	else if (so_long->map[line][column] == 'X')
		move_to_enemy(so_long);
}
