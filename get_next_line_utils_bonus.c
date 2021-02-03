/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:29:14 by gavril            #+#    #+#             */
/*   Updated: 2020/12/30 22:02:27 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char		*ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	ind;

	ind = 0;
	if (!src || !dst)
		return (0);
	if (sz != 0)
	{
		while (ind < sz - 1 && src[ind])
		{
			dst[ind] = src[ind];
			ind++;
		}
		dst[ind] = '\0';
	}
	return (dst);
}

size_t		ft_strchr(const char *str, int sym)
{
	size_t	ind;

	ind = 0;
	if (!str || !sym)
		return (0);
	while (str[ind] != '\0')
	{
		if (str[ind] == sym)
			return (ind + 1);
		ind++;
	}
	if (sym == '\0')
		return (ind + 1);
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ind1;
	size_t	ind2;
	char	*res;

	ind1 = 0;
	ind2 = 0;
	if (!(res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)
	* (sizeof(char))))))
		return (NULL);
	while (s1[ind1] != '\0')
	{
		res[ind1] = s1[ind1];
		ind1++;
	}
	while (s2[ind2])
	{
		res[ind1] = s2[ind2];
		ind1++;
		ind2++;
	}
	res[ind1] = '\0';
	return (res);
}

t_list		*lst_search(int fd, t_list **lst)
{
	t_list *tmp;

	if (!(*lst))
	{
		if (!(*lst = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		(*lst)->fd = fd;
		(*lst)->next = NULL;
		(*lst)->data = NULL;
		return (*lst);
	}
	tmp = *lst;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (!(tmp->next = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->next->next = NULL;
	tmp->next->data = NULL;
	return ((tmp->next->fd = fd) ? tmp->next : NULL);
}
