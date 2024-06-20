/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:42:49 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:25:40 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	send_error(char *str)
{
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_size(t_so_long *so_long)
{
	if (so_long->map_size.line > 34 || so_long->map_size.column > 64)
	{
		free_matrix(so_long->map);
		send_error(SIZE_ERR);
	}
}
