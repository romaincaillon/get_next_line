/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:27:01 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 16:43:17 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2 || *s1 == '\0')
		return (*s1 - *s2);
	else
		return (ft_strcmp(s1 + 1, s2 + 1));
}
