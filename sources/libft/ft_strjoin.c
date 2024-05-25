/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:54:07 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/25 19:50:02 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s = (char *)malloc(sizeof(char const)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

// char	*ft_join(char const *s1, char const *s2)
// {
// 	char *temp;
// 	char *s;
	
// 	temp = ft_strjoin(s1, "\n");
// 	s = ft_strjoin(temp, s2);
// 	free(temp);
// 	return (s);
// }

char	*ft_join(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s = (char *)malloc(sizeof(char const)
			* (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	if (i != 0)
		s[i++] = '\n';
	while (s2[j] != '\0')
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
