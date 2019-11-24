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

int		gnl_is_line(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		gnl_approve(char **str, char **line, int ret)
{
	int		boool;
	int		i;

	i = 0;
	if ((boool = gnl_is_line(*str)) || (ret == 0 && (**str && *str)))
	{
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		*line = ft_substr(*str, 0, i);
		if (!(*line))
			return (-1);
		*str = ft_substr(*str, i + 1, ft_strlen(*str));
		if (!(str))
			return (-1);
		if (boool)
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buff[((BUFFER_SIZE < 0) ? 0 : BUFFER_SIZE) + 1];
	int			ret;
	int			pb;
	char		*tmp;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE == 0 || line == 0)
		return (-1);
	while (ret || (ret == 0 && (str && *str)))
	{
		if ((pb = gnl_approve(&str, line, ret)) == 1)
			return (1);
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1 || pb == -1)
			return (-1);
		buff[ret] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buff);
		free(tmp);
		if (!(str))
			return (-1);
	}
	if (ret == 0)
		*line = ft_calloc(sizeof(char), 1);
	return (0);
}
