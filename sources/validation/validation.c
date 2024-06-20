/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/20 17:26:16 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_name(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		send_error(ARG_ERR);
	len = ft_strlen(argv[1]) - 4;
	if (len <= 0 || ft_strncmp(".ber", argv[1] + len, 4) != 0)
		send_error(FILE_NAME_ERR);
}

static void	clean_map(char **argv, t_so_long *so_long)
{
	int		fd;
	char	*str;
	char	*temp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		send_error(FILE_OPEN_ERR);
	str = read_map(fd);
	close(fd);
	check_chars(str, so_long);
	temp = check_chars_quantity(so_long);
	if (temp)
		send_error(temp);
	temp = ft_trim(str, " \t\v\n");
	free(str);
	if (line_contains_spaces(temp, " \t\v"))
		send_error(EMPTY_LINE_ERR);
	str = temp;
	so_long->map = ft_split(str, '\n');
	free(str);
}

static void	check_rectangle(t_so_long *so_long)
{
	int	i;
	int	len;
	int	temp;

	i = 1;
	if (!so_long->map || !so_long->map[0])
	{
		free_matrix(so_long->map);
		send_error("ERROR\n");
	}
	len = ft_strlen(so_long->map[0]);
	while (so_long->map[i])
	{
		temp = ft_strlen(so_long->map[i]);
		if (temp != len)
		{
			free_matrix(so_long->map);
			send_error(RECTANGLE_ERR);
		}
		i++;
	}
	so_long->map_size.column = len;
	so_long->map_size.line = i;
}

static void	check_walls(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->map_size.column)
	{
		if (so_long->map[0][i] != '1' || so_long->map[so_long->map_size.line
			- 1][i] != '1')
		{
			free_matrix(so_long->map);
			send_error(WALL_ERR);
		}
		i++;
	}
	i = 1;
	while (i < so_long->map_size.line - 2)
	{
		if (so_long->map[i][0] != '1'
			|| so_long->map[i][so_long->map_size.column - 1] != '1')
		{
			free_matrix(so_long->map);
			send_error(WALL_ERR);
		}
		i++;
	}
}

void	parse(int argc, char **argv, t_so_long *so_long)
{
	check_name(argc, argv);
	clean_map(argv, so_long);
	check_rectangle(so_long);
	check_walls(so_long);
	check_map_is_playable(so_long);
	check_size(so_long);
}
