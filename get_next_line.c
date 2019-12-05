/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:56:39 by grezette          #+#    #+#             */
/*   Updated: 2019/11/24 11:03:06 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*free_str(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

int		ft_read(char **dst, int fd)
{
	int		ret;
	char	*buff;

	ret = 0;
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	while (check_str(*dst) == 0 && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(*dst = ft_strjoin(*dst, buff)))
		{
			buff = free_str(buff);
			return (0);
		}
	}
	if (ret == -1)
	{
		buff = free_str(buff);
		return (-1);
	}
	buff = free_str(buff);
	return (1);
}

int		get_line(char ***line, char **dst)
{
	int result;

	result = 0;
	**line = free_str(**line);
	if (!(**line = ft_strdup(*dst)))
	{
		**line = free_str(**line);
		*dst = free_str(*dst);
		return (-1);
	}
	if (!(*dst = ft_substr(*dst)))
	{
		**line = free_str(**line);
		*dst = free_str(*dst);
		return (-1);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*dst = NULL;
	int			ret;

	ret = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(*line = ft_calloc(1, 1)))
		return (-1);
	if (dst != NULL && check_str(dst))
		return (get_line(&line, &dst));
	ret = ft_read(&dst, fd);
	if (check_str(dst) == 0 && ret > 0)
	{
		*line = free_str(*line);
		if (!(*line = ft_strdup(dst)))
		{
			*line = free_str(*line);
			dst = free_str(dst);
			return (-1);
		}
		dst = free_str(dst);
		return (0);
	}
	if (ret > 0)
		return (get_line(&line, &dst));
	return (-1);
}
