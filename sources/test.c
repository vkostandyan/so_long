/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:44:54 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/24 19:42:42 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    int fd = open("./maps/map.ber", O_RDONLY);
    printf("%d\n", fd);
    char *str;
    char *res = "";
    char *temp;
    char *temp_str;
    int flag = 0;
    
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        temp_str = ft_strtrim(str, " \t\v");
        temp = res;
        res = ft_strjoin(temp, str);
        if (flag)
            free(temp);
        free(str);
        free(temp_str);  
        flag = 1;
    } 
    printf("%s", res);
    free(res);
    close(fd);
    // system("leaks a.out");
    return (0);
}

// int main()
// {
//     int fd = open("./maps/map.ber", O_RDONLY);
//     printf("%d\n", fd);
//     char *str;
//     char *res = "";
//     char *temp;
//     char *temp_str;
//     int flag = 0;
    
//     while (1)
//     {
//         str = get_next_line(fd);
//         if (!str)
//             break;
//         // temp_str = str;
//         temp_str = ft_strtrim(str, " \t\v");
//         // free(str);
//         temp = res;
//         res = ft_strjoin(temp, temp_str);
//         if (flag)
//             free(temp);
//         free(str);
//         flag = 1;
//     } 
//     printf("%s", res);
//     free(res);
//     system("leaks a.out");
//     return (0);
// }