/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:43 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 14:25:44 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_len;
	size_t dst_len;
	size_t i;

	src_len = ft_strlen(src);
	i = 0;
	while (i < size - 1 && dst[i] != '\0')
		i++;
	if (dst[i] != '\0')
		return (size + src_len);
	dst_len = i;
	i = 0;
	while (dst_len + i < size - 1 && i < src_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
