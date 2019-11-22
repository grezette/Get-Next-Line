/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:39:01 by grezette          #+#    #+#             */
/*   Updated: 2019/11/16 15:57:05 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!(s))
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void 		*tab;
	unsigned char 	*str;
	size_t		n;

	if (!(tab = (void *)malloc(count * size)))
		return (NULL);
	str = tab;
	n = count * size;
	if (tab)
		while (n--)
			*str++ = 0;
	return (tab);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char *s;
	unsigned char		*d;

	if (!(src) && !(dst))
		return (NULL);
	s = src;
	d = dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!(s))
		return (NULL);
	if (start > ft_strlen(s))
		return (str = (char *)ft_calloc(1, 1));
	size = ft_strlen(&s[start]) + 1;
	if (size > len)
		size = len;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_memcpy(str, &s[start], size);
	str[size] = 0;
	if (s && start)
	{
		free(s);
		s = 0;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	size;

	size = 1;
	if (s1)
		size = ft_strlen(s1) + 1;
	if (s2)
		size += ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(*join) * size)))
		return (NULL);
	if (s1)
		ft_memcpy(join, s1, ft_strlen(s1));
	if (s2)
		ft_memcpy(&join[size - ft_strlen(s2) - 1], s2, ft_strlen(s2));
	join[size - 1] = 0;
	if (s1)
	{
		free(s1);
		s1 = 0;
	}
	return (join);
}
