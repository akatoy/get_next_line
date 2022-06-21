/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguiglio <yguiglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:55:44 by yguiglio          #+#    #+#             */
/*   Updated: 2022/05/24 16:06:02 by yguiglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	temp = malloc(ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	temp[i] = '\0';
	return (temp);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((ft_strlen (s1, '\0') + 1) * sizeof(char));
	if (dst == 0)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
