/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:34:59 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/15 16:19:21 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 8

int		get_next_line(const int fd, char **line);

#endif
