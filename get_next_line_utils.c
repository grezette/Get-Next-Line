/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:39:01 by grezette          #+#    #+#             */
/*   Updated: 2019/11/23 19:12:03 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	unsigned int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = NULL;
	s3 = free_str(s3);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s1 = free_str(s1);
	while (s2 && j < BUFFER_SIZE && s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[len] = '\0';
	return (s3);
}

char	*ft_substr(char *s)
{
	int		i;
	int		start;
	char	*s2;
	int		len;

	i = 0;
	start = 0;
	if (s == 0)
		return (NULL);
	while (s[start] != '\n')
		start++;
	start = start + 1;
	len = ft_strlen(s) - start;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		s2[i++] = s[start++];
	s2[len] = '\0';
	s = free_str(s);
	return (s2);
}

char	*ft_strdup(char *dst)
{
	unsigned int	i;
	unsigned int	len;
	char			*cpy;

	i = 0;
	len = 0;
	while ((size_t)len < ft_strlen(dst) && dst[len] != '\n')
		len++;
	if (!(cpy = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		cpy[i] = dst[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!(ptr = malloc(size * count)))
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 1;
		i++;
	}
	return (ptr);
}
