/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:07:20 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 22:10:28 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	first;
	size_t	last;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	first = 0;
	while (is_space(s[first]))
		first++;
	last = s_len - 1;
	while (is_space(s[last]) && last > 0)
		last--;
	if (last < first)
		return (ft_strdup(""));
	else
		return (ft_strsub(s, first, last - first + 1));
}
