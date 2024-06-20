/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:41:42 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:28:02 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_position(t_so_long *so_long, char direction)
{
	if (direction == 'U')
		so_long->player_position.line--;
	else if (direction == 'D')
		so_long->player_position.line++;
	else if (direction == 'R')
		so_long->player_position.column++;
	else if (direction == 'L')
		so_long->player_position.column--;
}

static void	print_step(t_so_long *so_long)
{
	int		i;
	char	*step;

	step = ft_itoa(so_long->step);
	i = 0;
	while (i < so_long->map_size.column)
	{
		put_image_to_window(so_long, 0, i, '1');
		i++;
	}
	mlx_string_put(so_long->mlx, so_long->window, 0, 0, 0XFFFFFF, "Steps: ");
	mlx_string_put(so_long->mlx, so_long->window, 70, 0, 0XFFFFFF, step);
	free(step);
}

int	movement(int keycode, t_so_long *so_long)
{
	if (keycode == UP_KEY)
		move_to(so_long, so_long->player_position.line - 1,
			so_long->player_position.column, 'U');
	else if (keycode == DOWN_KEY)
		move_to(so_long, so_long->player_position.line + 1,
			so_long->player_position.column, 'D');
	else if (keycode == LEFT_KEY)
		move_to(so_long, so_long->player_position.line,
			so_long->player_position.column - 1, 'L');
	else if (keycode == RIGHT_KEY)
		move_to(so_long, so_long->player_position.line,
			so_long->player_position.column + 1, 'R');
	else if (keycode == KEY_ESC)
		end_game(so_long);
	print_step(so_long);
	return (0);
}
