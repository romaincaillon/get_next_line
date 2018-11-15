/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:10:12 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 21:57:54 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	s_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new = ft_strnew(s_len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
