/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:58:26 by grezette          #+#    #+#             */
/*   Updated: 2019/11/23 21:13:43 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdlib.h>
# include <unistd.h>

# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
