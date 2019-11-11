/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:58:26 by grezette          #+#    #+#             */
/*   Updated: 2019/11/11 17:59:38 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

typedef struct	s_buff
{
	char	*buff[(BUFFER_SIZE < 0) ? 0 : BUFFER_SIZE];
	size_t	rd;
	size_t	current;
}				t_buff;

#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);

#endif
