/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:34:30 by rcaillon          #+#    #+#             */
/*   Updated: 2018/11/16 11:30:53 by rcaillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_new_file(t_list **files, int fd)
{
	t_list	*new_file;
	void	*new_content;
	int		*p_fd;
	char	**p_str;

	new_content = malloc(sizeof(int) + sizeof(char *));
	if (new_content == NULL)
		return (NULL);
	p_fd = (int *)new_content;
	p_str = (char **)(new_content + sizeof(int));
	*p_fd = fd;
	*p_str = ft_strnew(0);
	if (*p_str == NULL)
	{
		free(new_content);
		return (NULL);
	}
	new_file = ft_lstnew(new_content, sizeof(int) + sizeof(char *));
	free(new_content);
	if (new_file == NULL)
		return (NULL);
	ft_lstadd(files, new_file);
	return (new_file);
}

static t_list	*get_file(t_list **files, int fd)
{
	t_list	*file;

	if (files == NULL)
		return (NULL);
	file = *files;
	while (file != NULL)
	{
		if (*((int *)(file->content)) == fd)
			return (file);
		file = file->next;
	}
	return (get_new_file(files, fd));
}

static int		read_file(int fd, char **endline, char **p_save)
{
	ssize_t	res;
	char	buff[BUFF_SIZE + 1];
	char	*joined_str;

	res = 0;
	if (*p_save == NULL)
		return (1);
	while ((*endline = ft_strchr(*p_save, '\n')) == NULL &&
		(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		joined_str = ft_strjoin(*p_save, buff);
		ft_strswap(p_save, &joined_str);
		free(joined_str);
		if (*p_save == NULL)
			return (1);
	}
	return (res >= 0 ? 0 : 1);
}

static int		fill_line(char **line, char **p_save, char *endline)
{
	char *tmp;

	if (endline != NULL)
	{
		*line = ft_strsub(*p_save, 0, (size_t)(endline - *p_save));
		if (!*line)
			return (1);
		tmp = ft_strdup(endline + 1);
		if (!tmp)
			return (1);
		free(*p_save);
		*p_save = tmp;
	}
	else
	{
		*line = ft_strnew(0);
		if (!*line)
			return (1);
		ft_strswap(line, p_save);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files = NULL;
	t_list			*file;
	char			*endline;
	char			**p_save;

	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	file = get_file(&files, fd);
	if (!file)
		return (-1);
	p_save = (char **)(file->content + sizeof(int));
	if (!p_save)
		return (-1);
	if (read_file(fd, &endline, p_save) == 1)
		return (-1);
	if (fill_line(line, p_save, endline) == 1)
		return (-1);
	if ((endline == NULL && *p_save[0] == '\0' && *line[0] == '\0'))
	{
		free(*line);
		return (0);
	}
	else
		return (1);
}
