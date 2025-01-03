/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:45:11 by dmarijan          #+#    #+#             */
/*   Updated: 2025/01/03 14:24:53 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*cutline(int start, char **buffer, int bufferlen)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_calloc(bufferlen - start + 1, sizeof(char));
	if (!temp)
		return (ft_free(&*buffer));
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
	ft_free(&*buffer);
	return (temp);
}

char	*copyline(char **buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[0][i] && buffer[0][i] != '\n')
		i++;
	if (buffer[0][i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (ft_free(&*buffer));
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

char	*fillbuffer(int fd, char **buffer)
{
	int		bread;
	char	*temp;

	bread = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (ft_free(&*buffer));
	while (bread > 0 && ft_strchr(*buffer, '\n') == -1)
	{
		bread = read(fd, temp, BUFFER_SIZE);
		if (bread == -1)
		{
			free(temp);
			return (ft_free(&*buffer));
		}
		temp[bread] = '\0';
		*buffer = ft_strjoin(*buffer, temp);
	}
	free(temp);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	buffer = fillbuffer(fd, &buffer);
	if (!buffer)
		return (ft_free(&buffer));
	line = copyline(&buffer);
	if (buffer)
		buffer = cutline(ft_strlen(line), &buffer, ft_strlen(buffer));
	return (line);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int fd = open(av[1], O_RDWR);
	char *str = get_next_line(fd);
	//int	i = 0;
	while (str)
	{
		//printf("____\n%d iteration\n____\n%s", i++, str);
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}
