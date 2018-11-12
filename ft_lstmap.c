/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:01:20 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/12 09:01:22 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	(void)content_size;
	if (content != NULL)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_start;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_start = f(lst);
	if (new_start == NULL)
		return (NULL);
	new = new_start;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = f(lst);
		if (new->next == NULL)
		{
			ft_lstdel(&new_start, &del);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (new_start);
}
