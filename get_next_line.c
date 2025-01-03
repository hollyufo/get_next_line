/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:43 by imchaibi          #+#    #+#             */
/*   Updated: 2025/01/03 16:34:58 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

ssize_t	gnl_buff(char *buffer, char *remainder, int fd)
{
	size_t	i;

	if (remainder[0] != '\0')
	{
		ft_strlcpy(buffer, remainder, BUFFER_SIZE + 1);
		remainder[0] = '\0';
		return (ft_strlen(buffer));
	}
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
	return (read(fd, buffer, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE + 1];
	static char	remainder[BUFFER_SIZE + 1] = {0};
	char		*line;
	char		*nl;

	line = NULL;
	while (1)
	{
		bytes_read = gnl_buff(buffer, remainder, fd);
		if (bytes_read <= 0)
		{
			return (line);
		}
		nl = ft_strchr(buffer, '\n');
		if (nl)
		{
			*nl = '\0';
			line = ft_strjoin(line, buffer);
			ft_strlcpy(remainder, nl + 1, BUFFER_SIZE + 1);
			return (line);
		}
		line = ft_strjoin(line, buffer);
	}
}
