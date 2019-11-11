/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:56:39 by grezette          #+#    #+#             */
/*   Updated: 2019/11/11 17:59:33 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_that_line(char *buff)
{
	char *line;
	int i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(*line) * (i + 1))))
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static t_buff var;

	var->rd = read(fd, var->buff, BUFFER_SIZE);
	if (var->rd <= -1)
		return (-1);
	else if (var->rd > 0)
	{
		*line = get_that_line(var->buff);
		if (var->r < BUFFER_SIZE)
			return (0);
		else
			return (1);
	}
	return (0);
}
