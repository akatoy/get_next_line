/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguiglio <yguiglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:27:00 by yguiglio          #+#    #+#             */
/*   Updated: 2022/05/24 16:13:28 by yguiglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	verify_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*mini_strtrim_line(char *str)
{
	int		i;
	char	*line;

	if (str == NULL)
		return (NULL);
	i = 0;
	line = malloc(ft_strlen(str, '\n') + 2);
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	free(str);
	return (line);
}

void	mini_strtrim_buf(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return ;
	else
	{
		i++;
		while (str[i] != '\0')
		{
			str[j] = str[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
}

char	*get_next_line(int fd)
{
	ssize_t		temp;
	char		*line;
	static char	buf[BUFFER_SIZE + 1] = "";

	line = NULL;
	if (buf[0] != '\0')
		line = ft_strdup(buf);
	while (verify_new_line(buf) != 1)
	{
		temp = read(fd, buf, BUFFER_SIZE);
		if (temp < 0)
			return (free(line), NULL);
		buf[temp] = '\0';
		if (temp == 0)
			break ;
		if (line == NULL)
			line = ft_strdup(buf);
		else
			line = ft_strjoin(line, buf);
	}
	line = mini_strtrim_line(line);
	mini_strtrim_buf(buf);
	if (line && line[0] == 0)
		return (free(line), NULL);
	return (line);
}
