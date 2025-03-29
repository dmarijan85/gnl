/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:11 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/29 12:23:04 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*b_ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*b_cutline(int start, char **buffer, int bufferlen)
{
	char	*temp;
	int		i;
	int		j;

	temp = b_ft_calloc(bufferlen - start + 1, sizeof(char));
	if (!temp)
		return (b_ft_free(&*buffer));
	i = 0;
	j = 0;
	while (buffer[0][i])
	{
		if (i >= start)
		{
			temp[j] = buffer[0][i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	b_ft_free(&*buffer);
	return (temp);
}

char	*b_copyline(char **buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[0][i] && buffer[0][i] != '\n')
		i++;
	if (buffer[0][i] == '\n')
		i++;
	line = b_ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (b_ft_free(&*buffer));
	i = 0;
	while (buffer[0][i] && buffer[0][i] != '\n')
	{
		line[i] = buffer[0][i];
		i++;
	}
	if (buffer[0][i] == '\n')
	{
		line[i] = buffer[0][i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*b_fillbuffer(int fd, char **buffer)
{
	int		bread;
	char	*temp;

	bread = 1;
	temp = b_ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (b_ft_free(&*buffer));
	while (bread > 0 && b_ft_strchr(*buffer, '\n') == -1)
	{
		bread = read(fd, temp, BUFFER_SIZE);
		if (bread == -1)
		{
			free(temp);
			return (b_ft_free(&*buffer));
		}
		temp[bread] = '\0';
		*buffer = b_ft_strjoin(*buffer, temp);
	}
	free(temp);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = b_ft_calloc(1, sizeof(char));
		if (!buffer[fd])
			return (NULL);
	}
	buffer[fd] = b_fillbuffer(fd, &buffer[fd]);
	if (!buffer[fd])
		return (b_ft_free(&buffer[fd]));
	line = b_copyline(&buffer[fd]);
	if (buffer[fd])
		buffer[fd] = b_cutline(b_ft_strlen(line), \
				&buffer[fd], b_ft_strlen(buffer[fd]));
	return (line);
}
/*int	main()
{
	char	*string;

	string = malloc(4*sizeof(char));
	string = "lmao";
	puts(string);
	string = malloc(2*sizeof(char));
	string = "ABCD(";
	puts(string);
}
*/
