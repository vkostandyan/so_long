/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:27 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/23 21:43:40 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    // t_so_long so_long;
    
    // parse(argc, argv); 
    // so_long = init_map();
    // printf("alo\n");
    // printf("%d\n", so_long.line_len);  
    (void)argc;
    (void)argv;
    int fd = open("map.ber", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s\n", str);
    return (0);
}
