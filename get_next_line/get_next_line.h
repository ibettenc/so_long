/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:19:00 by ibettenc          #+#    #+#             */
/*   Updated: 2025/07/12 15:41:56 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // read, close
# include <fcntl.h> // open, O_RDONLY
# include <stdint.h> // size_max

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
void	free_stash(char **stash);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);

#endif
