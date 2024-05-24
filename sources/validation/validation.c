/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/24 22:19:51 by vkostand         ###   ########.fr       */
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

// void check_redundant_chars(char *str, char *set)
// {
//     int i = 0;
//     while (char_match(str[i], set))
//         i++;
//     if (str[i])
//         send_error(CHAR_ERR);
// }    

void check_chars(char *str, t_so_long *so_long)
{
    int i;

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
        else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v')
        {
            free(str);
            send_error(CHAR_ERR);
        }
        i++;
    }
}

char *read_map(int fd)
{
    char *str;
    char *res = "";
    char *temp;
    char *temp_str;
    int flag;
    
    flag = 0;
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
    return (res);
}

char **split_map(char *file_name, t_so_long *so_long)
{
    int fd;
    char **map;
    
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (NULL);
    char *str = read_map(fd);
    check_chars(str, so_long);
    map = ft_split(str, '\n');
    free(str);
    close (fd);
    return (map);
}

int is_empty_line(char *str)
{
    int i;

    i = 0;
    while (str[i] && char_match(str[i], " \t\v"))
        i++;
    if (str[i])
        return (0);
    return (1);
}

void parse(int argc, char **argv, t_so_long *so_long)
{
    (void)argv;
    if (argc != 2)
        send_error(ARG_ERR);
    check_name(argv[1]);
    char **arr = split_map(argv[1], so_long);
    int i = 0;
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
    free_matrix(arr);
}
