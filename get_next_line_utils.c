/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:04:05 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/29 12:23:14 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	char	*str;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	str = ptr;
	while (count)
	{
		*ptr = '\0';
		ptr++;
		count--;
	}
	return (str);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dst, char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!src || !dst)
		return (NULL);
	str = ft_calloc(((ft_strlen(dst) + ft_strlen(src)) + 1), sizeof(char));
	if (!str)
		return (ft_free(&dst));
	i = 0;
	j = 0;
	while (dst[i])
	{
		str[i] = dst[i];
		i++;
	}
	while (src[j])
		str[i++] = src[j++];
	str[i] = '\0';
	ft_free(&dst);
	if (!str[0])
		return (ft_free(&str));
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}
