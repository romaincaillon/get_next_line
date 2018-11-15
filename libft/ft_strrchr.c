/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:50 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 16:42:53 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		res = (char *)s + i;
	return (res);
}
