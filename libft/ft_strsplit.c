/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:53:08 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/12 09:00:30 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	count_words(char const *s, char c)
{
	size_t			i;
	unsigned long	nb_words;

	nb_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static size_t			get_word_len(char const *word, char c)
{
	size_t i;

	i = 0;
	while (word[i] != c && word[i] != '\0')
		i++;
	return (i);
}

static void				free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void				fill_tab(char ***tab, char const *s, char c,
							unsigned long nb_words)
{
	unsigned long	nb_assigned_words;
	size_t			word_len;

	nb_assigned_words = 0;
	while (nb_assigned_words < nb_words)
	{
		while (*s == c)
			s++;
		word_len = get_word_len(s, c);
		(*tab)[nb_assigned_words] = ft_strsub(s, 0, word_len);
		if ((*tab)[nb_assigned_words] == NULL)
		{
			free_tab(*tab);
			*tab = NULL;
			return ;
		}
		nb_assigned_words++;
		s += word_len;
	}
	(*tab)[nb_words] = NULL;
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned long	nb_words;
	char			**tab;

	if (s == NULL)
		return (NULL);
	nb_words = count_words(s, c);
	tab = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	fill_tab(&tab, s, c, nb_words);
	return (tab);
}
