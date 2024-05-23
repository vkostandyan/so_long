/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:41:32 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/23 21:41:24 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_so_long init_map()
{
    int fd;
    char *str;
    t_so_long so_long;

    fd = open("map.ber", O_RDONLY);
    printf("%d\n", fd);
    if (fd == -1)
        send_error(FILE_OPEN_ERR);
    str = get_next_line(fd);
    printf("%s\n", str);
    if (str)
        so_long.line_len = ft_strlen(str);
    else
        so_long.line_len = -1;
    return (so_long);
}