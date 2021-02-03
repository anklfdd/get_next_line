/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:59:28 by gavril            #+#    #+#             */
/*   Updated: 2020/12/30 22:00:03 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

int			get_next_line(int fd, char **line);
size_t		ft_strchr(const char *str, int sym);
char		*ft_strlcpy(char *dst, const char *src, size_t sz);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
