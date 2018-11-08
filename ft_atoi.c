/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:36 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/08 18:30:07 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t'
			|| c == '\n'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int			ft_atoi(const char *str)
{
	int i;
	int res;
	int symbol;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		symbol = str[i] == '+' ? 1 : -1;
		i++;
	}
	else
		symbol = 1;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + i - '0';
		i++;
	}
	return (symbol * res);
}
