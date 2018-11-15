/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:56:33 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 22:07:21 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = ft_strnew(s1_len + s2_len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		new[s1_len + i] = s2[i];
		i++;
	}
	return (new);
}
