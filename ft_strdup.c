/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:05 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 16:41:02 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*cpy;

	length = ft_strlen(s);
	cpy = (char *)malloc(length * sizeof(char) + 1);
	if (cpy == NULL)
		return (NULL);
	while (length > 0)
	{
		cpy[length] = s[length];
		length--;
	}
	cpy[0] = s[0];
	return (cpy);
}
