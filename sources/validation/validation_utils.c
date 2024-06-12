/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:11:07 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/12 20:19:53 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_contains_spaces(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i] && !char_match(str[i], set))
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	if (str[i])
		return (1);
	return (0);
}

int	is_empty_line(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i] && char_match(str[i], set))
		i++;
	if (str[i])
		return (0);
	return (1);
}

char	*read_map(int fd)
{
	char	*current_line;
	char	*result;
	char	*temp;
	char	*current_temp;

	result = "";
	while (1)
	{
		current_line = get_next_line(fd);
		if (!current_line)
			break ;
		temp = result;
		if (!is_empty_line(current_line, " \n\t\v"))
		{
			current_temp = ft_strtrim(current_line, " \n\t\v");
			result = ft_join(temp, current_temp);
			free(current_temp);
		}
		else
			result = ft_strjoin(temp, current_line);
		if (ft_strncmp(result, current_line, ft_strlen(result)) != 0)
			free(temp);
		free(current_line);
	}
	return (result);
}

void	check_chars(char *str, t_so_long *so_long)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			so_long->counter.wall++;
		else if (str[i] == '0')
			so_long->counter.empty_space++;
		else if (str[i] == 'E')
			so_long->counter.exit++;
		else if (str[i] == 'C')
			so_long->counter.coin++;
		else if (str[i] == 'P')
			so_long->counter.player++;
		else if (str[i] == 'O')
			so_long->counter.enemy++;
		else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
			&& str[i] != '\v')
		{
			free(str);
			send_error(CHAR_ERR);
		}
		i++;
	}
}

char	*check_chars_quantity(t_so_long *so_long)
{
	if (so_long->counter.wall < 1)
		return ("Error\n");
	if (so_long->counter.coin < 1)
		return (COIN_ERR);
	if (so_long->counter.exit != 1)
		return (EXIT_ERR);
	if (so_long->counter.player != 1)
		return (PLAYER_ERR);
	return (NULL);
}
