/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:43 by imchaibi          #+#    #+#             */
/*   Updated: 2024/12/15 18:10:41 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	gnl_buff(char *buffer, char *remainder, int fd)
{
	size_t	i;

	if (remainder[0] != '\0')
	{
		ft_strcpy(buffer, remainder);
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
	char		buffer[BUFFER_SIZE + 1];
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
			ft_strcpy(remainder, nl + 1);
			return (line);
		}
		line = ft_strjoin(line, buffer);
	}
}
