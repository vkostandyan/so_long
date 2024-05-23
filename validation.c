/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/23 19:10:39 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_name(char *av)
{
    int len;

    len = ft_strlen(av) - 4;
    if (len <= 0 || ft_strncmp(".ber", av + len, 4) != 0)
        send_error(FILE_NAME_ERR);
}

void parse(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        send_error(ARG_ERR);
    check_name(argv[1]);
}
