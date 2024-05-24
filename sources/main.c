/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:29:27 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/24 22:07:53 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_struct(t_so_long *so_long)
{
    so_long->counter.player = 0;
    so_long->counter.enemy = 0;
    so_long->counter.exit = 0;
    so_long->counter.coin = 0;
    so_long->counter.wall = 0;
    so_long->counter.wall = 0;
    so_long->line = 0;
    so_long->line_len = 0;
}

int main(int argc, char **argv)
{
    t_so_long so_long;
    
    init_struct(&so_long);
    parse(argc, argv, &so_long);
    // system("leaks a.out");
    return (0);
}

// int main(int argc, char **argv)
// {
//     // // t_so_long so_long;
    
//     // // parse(argc, argv); 
//     // // so_long = init_map();
//     // // printf("alo\n");
//     // // printf("%d\n", so_long.line_len);  
//     // (void)argc;
//     // (void)argv;
//     // int fd = open("map.ber", O_RDONLY);
//     // char *str = get_next_line(fd);
//     // printf("%s\n", str);
//     return (0);
// }
