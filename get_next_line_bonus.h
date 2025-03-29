/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:31:11 by dmarijan          #+#    #+#             */
/*   Updated: 2025/03/29 12:23:08 by dmarijan         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*b_ft_strjoin(char *dst, char *src);
size_t	b_ft_strlen(char *str);
int		b_ft_strchr(char *s, int c);
char	*b_ft_calloc(size_t count, size_t size);
char	*b_ft_free(char **str);

#endif
