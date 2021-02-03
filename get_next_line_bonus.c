/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:29:45 by gavril            #+#    #+#             */
/*   Updated: 2020/12/30 22:03:52 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	write_in_line(char **line, char **data, char *buf)
{
	char *tmp;

	tmp = NULL;
	if (*data && !buf)
	{
		if (!(*line = (char *)malloc(sizeof(char) * ft_strchr(*data, '\n'))))
			return (-1);
		*line = ft_strlcpy(*line, *data, ft_strchr(*data, '\n'));
		tmp = *data;
		*data = ft_strjoin(tmp + ft_strchr(*data, '\n'), "");
		free(tmp);
		tmp = NULL;
	}
	else if (data && buf)
	{
		if (!(*line = (char *)malloc(sizeof(char) * ft_strchr(buf, '\n'))))
			return (-1);
		*line = ft_strlcpy(*line, buf, ft_strchr(buf, '\n'));
		tmp = *data;
		*data = ft_strjoin(buf + ft_strchr(buf, '\n'), "");
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

static char	*strjoin_data_buf(char *data, char *buf)
{
	char *tmp;

	tmp = data;
	data = ft_strjoin(tmp, buf);
	free(tmp);
	tmp = NULL;
	return (data);
}

static int	reading_file(char **data, char **buf, char **line)
{
	if (ft_strchr(*buf, '\n'))
	{
		if (*data)
		{
			*data = strjoin_data_buf(*data, *buf);
			write_in_line(line, data, 0);
			return (1);
		}
		else if (!(*data))
		{
			write_in_line(line, data, *buf);
			return (1);
		}
	}
	else if (!(ft_strchr(*buf, '\n')))
	{
		if (*data)
			*data = strjoin_data_buf(*data, *buf);
		else if (!(*data))
			*data = ft_strjoin(*buf, "");
	}
	return (0);
}

static int	write_last_line(char **data, char **line)
{
	size_t	a;

	a = 0;
	if (*data != NULL)
	{
		while (((*data)[a]) != '\0')
			a++;
		if (!(*line = (char *)malloc(sizeof(char) * a + 1)))
			return (-1);
		*line = ft_strlcpy(*line, *data, a + 1);
		free(*data);
		*data = NULL;
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (-1);
		*line[0] = '\0';
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	ssize_t			ret_read;
	static t_list	*lst;
	t_list			*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || (!(buf =
	(char*)malloc(sizeof(char) * BUFFER_SIZE + 1))) || (read(fd, buf, 0)) == -1)
		return (-1);
	if ((tmp = lst_search(fd, &lst)) && tmp->data && ft_strchr(tmp->data, '\n'))
	{
		write_in_line(line, &(tmp->data), 0);
		free(buf);
		return (1);
	}
	while ((ret_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret_read] = '\0';
		if ((reading_file(&(tmp->data), &buf, line)) == 1)
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (write_last_line(&(tmp->data), line));
}
