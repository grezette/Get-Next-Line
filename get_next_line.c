/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:56:39 by grezette          #+#    #+#             */
/*   Updated: 2019/11/17 20:14:03 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_is_bs(char *str)
{
		if (!str)
				return (0);
		while (*str)
		{
				if (*str == '\n')
						return (1);
				str++;
		}
		return (0);
}

int		ft_gnl_len_bs(char *str)
{
		int i;

		i = 0;
		while (str[i] && str[i] != '\n')
				i++;
		return (i);
}

int		ft_gnl_approve(char **line, char **str, int ret)
{
		int new;

		new = 0;
		if ((new = ft_gnl_is_bs(*str)) == 1 || (ret == 0 && (*str && **str)))
		{
				if (*line && line)
						free(*line);
				*line = ft_substr(*str, 0, ft_gnl_len_bs(*str));
				*str = ft_substr(*str, ft_strlen(*line) + 1, ft_strlen(*str));
				if (new == 1)
						return (1);
		}
		return (0);
}

int		get_next_line(int fd, char **line)
{
		char 		buff[((BUFFER_SIZE < 0) ? 0 : BUFFER_SIZE) + 1];
		static char		*str = NULL;
		int			ret;

		ret = 1;
		while (ret > 0 || (ret && (str && str)))
		{
				if (ft_gnl_approve(line, &str, ret))
						return (1);
				if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
						return (-1);
				buff[ret] = 0;
				if (ret)
						str = ft_strjoin(str, buff);
		}
		free(str);
		str = NULL;
		return (0);
}

int        main(int argc, char **argv)
{
		if (argc >= 1)
		{
				char *line;
				int nb;
				int fd;

				fd = open(argv[1], O_RDONLY);
				while ((nb = get_next_line(fd, &line) == 1))
						printf("%d : %s\n", nb, line);
		}
}
