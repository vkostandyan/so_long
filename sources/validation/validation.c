/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/25 20:33:03 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_name(int argc, char **argv)
{
    int len;

    if (argc != 2)
        send_error(ARG_ERR);
    len = ft_strlen(argv[1]) - 4;
    if (len <= 0 || ft_strncmp(".ber", argv[1] + len, 4) != 0)
        send_error(FILE_NAME_ERR);
} 

// void check_chars(char *str, t_so_long *so_long)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] == '1')
//             so_long->counter.wall++;
//         else if (str[i] == '0')
//             so_long->counter.empty_space++;
//         else if (str[i] == 'E')
//             so_long->counter.exit++;
//         else if (str[i] == 'C')
//             so_long->counter.coin++;
//         else if (str[i] == 'P')
//             so_long->counter.player++;
//         else if (str[i] == 'O')
//             so_long->counter.enemy++;
//         else if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\v')
//         {
//             free(str);
//             send_error(CHAR_ERR);
//         }
//         i++;
//     }
// }

// char *check_chars_quantity(t_so_long *so_long)
// {
//     if (so_long->counter.coin < 1)
//         return (COIN_ERR);
//     if (so_long->counter.exit != 1)
//         return (EXIT_ERR);
//     if (so_long->counter.player != 1)
//         return (PLAYER_ERR);
//     // if (so_long->counter.coin < 1)
//     //     return (COIN_ERR);
//     // if (so_long->counter.coin < 1)
//     //     return (COIN_ERR);
//     return (NULL);
// }

// char *read_map(int fd)
// {
//     char *str;
//     char *res = "";
//     char *temp;
//     // char *temp_str;
//     int flag;
    
//     flag = 0;
//     while (1)
//     {
//         str = get_next_line(fd);
//         if (!str)
//             break;
//         // temp_str = ft_strtrim(str, " \t\v");
//         temp = res;
//         res = ft_strjoin(temp, str);
//         if (flag)
//             free(temp);
//         free(str);
//         // free(temp_str);  
//         flag = 1;
//     } 
//     return (res);
// }

// void remove_begin_end_spaces(char *str)
// {
//     int new_start;
//     int new_end;
//     char *new_str;

//     new_start = 0;
//     new_end = ft_strlen(str) - 1;
//     while (str[new_start] == ' ' || str[new_start] == '\v' || str[new_start] == '\t' || str[new_start] == '\n')
//         new_start++;
//     while (str[new_end] == ' ' || str[new_end] == '\v' || str[new_end] == '\t' || str[new_start] == '\n')
//         new_end++;
//     new_str = ft_substr(str, new_start, new_end - new_start);
//     printf("------------------------------------------\n");
//     printf("%s", new_str);
//     printf("\n------------------------------------------\n");
// }

// char **split_map(char *file_name, t_so_long *so_long)
// {
//     int fd;
//     char **map;
    
    
//     fd = open(file_name, O_RDONLY);
//     if (fd == -1)
//         return (NULL);
//     char *str = read_map(fd);
//     check_chars(str, so_long);
//     if (check_chars_quantity(so_long))
//     {
//         free(str);
//         send_error(check_chars_quantity(so_long));
//     }
//     // remove_begin_end_spaces(str);
//     map = ft_split(str, '\n');
//     free(str);
//     close (fd);
//     return (map);
// }



// -------------------------------------------



int is_empty_line(char *str, char *set)
{
    int i;

    i = 0;
    while (str[i] && char_match(str[i], set))
        i++;
    if (str[i])
        return (0);
    return (1);
}

int line_contains_spaces(char *str, char *set)
{
    int i;

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

char *check_chars_quantity(t_so_long *so_long)
{
    if (so_long->counter.coin < 1)
        return (COIN_ERR);
    if (so_long->counter.exit != 1)
        return (EXIT_ERR);
    if (so_long->counter.player != 1)
        return (PLAYER_ERR);
    // if (so_long->counter.coin < 1)
    //     return (COIN_ERR);
    // if (so_long->counter.coin < 1)
    //     return (COIN_ERR);
    return (NULL);
}

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
        else if (str[i] == 'O')
            so_long->counter.enemy++;
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
    char *current_line;
    char *result = "";
    char *temp;
    char *current_temp;

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

void clean_map(char **argv, t_so_long *so_long)
{
    int fd;
    char *str;
    char *temp;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        send_error(FILE_OPEN_ERR);
    str = read_map(fd);
    check_chars(str, so_long);
    temp = check_chars_quantity(so_long);
    if (temp)
    {
        free(str);
        send_error(CHAR_ERR);
    }
    temp = ft_trim(str, " \t\v\n");
    free(str);
    if (line_contains_spaces(temp, " \t\v"))
        send_error(EMPTY_LINE_ERR);
    str = temp;
    printf("%s\n\n", str);
    so_long->map = ft_split(str, '\n');
    int i = 0;
    while (so_long->map[i])
    {
        printf("%s\n", so_long->map[i]);
        i++;
    }
    free(str);
}

void parse(int argc, char **argv, t_so_long *so_long)
{
    check_name(argc, argv);
    clean_map(argv, so_long);
    // char **arr = split_map(argv[1], so_long);
    // int i = 0;
    // while (arr[i])
    // {
    //     printf("%s\n", arr[i]);
    //     i++;
    // }
    // free_matrix(arr);
}
