/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:02:58 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 22:39:20 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (*p1 != *p2 || *p1 == '\0')
		return (*p1 - *p2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
