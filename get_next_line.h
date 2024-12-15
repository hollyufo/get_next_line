/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:45 by imchaibi          #+#    #+#             */
/*   Updated: 2024/12/15 18:11:50 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
# include <stddef.h>
# include <stdlib.h> 
# include <stdint.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif 


char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int ft_strchr(char* line, char c);

#endif