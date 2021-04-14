/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:27:53 by rotrojan          #+#    #+#             */
/*   Updated: 2021/04/14 15:38:53 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

#endif
