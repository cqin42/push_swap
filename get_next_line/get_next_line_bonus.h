/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:23 by cqin              #+#    #+#             */
/*   Updated: 2023/01/15 12:20:24 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*GNL*/
char	*get_next_line(int fd);
char	*read_and_save(int fd, char *save);
char	*buffer_to_save(char *save, char *buffer);
char	*save_to_line(char *save);
char	*get_new_save(char *save, char *line);

/*utils*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);

#endif
