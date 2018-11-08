/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:24 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 16:40:17 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (*((unsigned char *)s1) != *((unsigned char *)s2))
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	else
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
}
