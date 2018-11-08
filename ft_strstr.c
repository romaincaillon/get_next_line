/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:33:06 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 15:00:36 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	start;
	size_t	i;
	int		found;

	if (*needle == '\0')
		return ((char *)haystack);
	start = 0;
	while (haystack[start] != '\0')
	{
		i = 0;
		found = 1;
		while (needle[i] != '\0' && found)
		{
			if (haystack[start + i] != needle[i])
				found = 0;
			i++;
		}
		if (found)
			return ((char *)haystack + start);
		start++;
	}
	return (NULL);
}
