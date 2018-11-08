/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:01:30 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 15:52:27 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	start;
	size_t	i;
	int		found;

	if (*needle == '\0')
		return ((char *)haystack);
	start = 0;
	while (haystack[start] != '\0' && start < len)
	{
		i = 0;
		found = 1;
		while (needle[i] != '\0' && found && start + i < len)
		{
			if (haystack[start + i] != needle[i])
				found = 0;
			i++;
		}
		if (found && needle[i] == '\0')
			return ((char *)haystack + start);
		start++;
	}
	return (NULL);
}
