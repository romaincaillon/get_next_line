/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:14:46 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 20:06:49 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static void		check_symbol(int *n, int *is_negative)
{
	if (*n < 0)
	{
		*is_negative = 1;
		*n *= -1;
	}
	else
		*is_negative = 0;
}

char			*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	check_symbol(&n, &is_negative);
	len = get_len(n);
	if (is_negative)
		len++;
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	while (len > 1 || (len > 0 && !is_negative))
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (is_negative)
		res[0] = '-';
	return (res);
}
