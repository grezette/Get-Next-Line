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

 int	ft_get_that_line(char **line, char *buff, int fctr, int len)
{
	int 	i;
	int		j;
	char	*tmp;

	tmp = *line;
	i = -1;
	j = -1;
	if (!(*line = (char *)malloc(sizeof(**line) * (BUFFER_SIZE * fctr + 1))))
	{
		free(tmp);
		tmp = NULL;
		return (-1);
	}
	while (tmp && tmp[++i])
		(*line)[i] = tmp[i];
	i = (i < 0) ? 0 : i;
	while (++j < len)
		(*line)[i + j] = buff[j];
	(*line)[i + j] = 0;
	i = 0;
	j++;
	while (buff[j])
		buff[i++] = buff[j++];
	buff[i] = 0;
	free(tmp);
	tmp = NULL;
	return (1);
}

char	*ft_gnl_join(char *line, char *buff, int fctr)
{
	int 	i;
	int 	j;
	char 	*str;

	i = -1;
	j = -1;
	if (!(str = (char *)malloc(sizeof(*str) * (BUFFER_SIZE * fctr + 1))))
	{
		free(line);
		return (line = NULL);
	}
	while (line && line[++i])
		str[i] = line[i];
	i = (i < 0) ? 0 : i;
	while (buff[++j])
		str[i + j] = buff[j];
	str[i + j] = 0;
	buff[0] = 0;
	free(line);
	line = NULL;
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			len;
	int			fctr;
	int			ret;

	fctr = 0;
	ret = 1;
	while (ret)
	{
		if (!(buff[0]))
		{
			ret = read(fd, buff, BUFFER_SIZE);
			buff[ret] = 0;
		}
		len = 0;
		while (buff[len] && buff[len] != '\n')
			len++;
		if (buff[len] == '\n')
			return (ft_get_that_line(line, buff, ++fctr, len));
		if (!(*line = ft_gnl_join(*line, buff, ++fctr)))
			return (-1);
	}
	return (0);
}
