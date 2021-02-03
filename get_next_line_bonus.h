/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:29:30 by gavril            #+#    #+#             */
/*   Updated: 2020/12/30 22:00:07 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

typedef struct		s_list
{
	char			*data;
	int				fd;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strchr(const char *str, int sym);
char				*ft_strlcpy(char *dst, const char *src, size_t sz);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*lst_search(int fd, t_list **lst);

#endif
