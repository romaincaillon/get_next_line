/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:02:25 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/12 09:02:26 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *link;
	t_list *tmp;

	if (alst == NULL || del == NULL)
		return ;
	link = *alst;
	while (link != NULL)
	{
		tmp = link;
		link = tmp->next;
		ft_lstdelone(&tmp, del);
	}
	*alst = NULL;
}
