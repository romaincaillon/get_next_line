/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:53:08 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/09 22:09:42 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	replace_sep_by_zero(char *cpy, size_t len, char c)
{
	size_t			i;
	unsigned long	nb_words;

	nb_words = 0;
	i = 0;
	while (i < len)
	{
		if (cpy[i] == c)
			cpy[i] = '\0';
		else if (i == 0 || cpy[i - 1] == '\0')
			nb_words++;
		i++;
	}
	return (nb_words);
}

static void				fill_tab(char **tab, char *cpy, size_t str_len,
									unsigned long nb_words)
{
	size_t			i;
	unsigned long	nb_assigned_words;

	i = 0;
	nb_assigned_words = 0;
	while (i < str_len && nb_assigned_words < nb_words)
	{
		if (cpy[i] != '\0' && (i == 0 || cpy[i - 1] == '\0'))
		{
			tab[nb_assigned_words] = cpy + i;
			nb_assigned_words++;
		}
		i++;
	}
	tab[nb_words] = NULL;
}

char					**ft_strsplit(char const *s, char c)
{
	size_t			s_len;
	char			*cpy;
	unsigned long	nb_words;
	char			**tab;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	cpy = ft_strdup(s);
	if (cpy == NULL)
		return (NULL);
	nb_words = replace_sep_by_zero(cpy, s_len, c);
	tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (tab == NULL)
	{
		free(cpy);
		return (NULL);
	}
	fill_tab(tab, cpy, s_len, nb_words);
	return (tab);
}
