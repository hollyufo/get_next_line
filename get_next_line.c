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
#include <string.h>

ssize_t gnl_buff(char *buffer,char *remainder, int fd){

	if (remainder[0] != '\0')
	{
		strcpy(remainder, buffer);
		remainder[0] = 0;
		return strlen(buffer);
	}
	bzero(buffer, BUFFER_SIZE + 1);
	return read(fd, buffer, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	static char remainder[BUFFER_SIZE + 1] = {0};
	char		*line;
	char		*tmp_line;
	long		nl_pos;

	line = NULL;
	nl_pos = 0;
	while (1)
	{
		nl_pos = gnl_buff(buffer, remainder, fd);
		// print the buffer and remainder and nl_pos
		printf("buffer: %s\n", buffer);
		printf("remainder: %s\n", remainder);
		printf("nl_pos: %ld\n", nl_pos);
		if (nl_pos == -1){ // read syscall failed
			free(line);
			return NULL;
		}
		else if (nl_pos == 0){
			return line; // it's the last line
		}
		tmp_line = ft_strjoin(line, buffer);// free line inside strjoin
		free(line);
		line = tmp_line;
		nl_pos = ft_strchr(line, '\n');
		if (nl_pos != -1)
		{
			strcpy(line + nl_pos, remainder);
			line[nl_pos + 1] = 0; 
			return line;
		}
	}

	return (line);
}



int main(int ac, char **av){
	if (ac != 2)
		return 0;

	int fd  = open(av[1], O_RDONLY);
	while (1){
		char *line = get_next_line(fd);
		if (!line)
			break;
		printf(">>>%s\n", line);
		free(line);
	}
	return 0;
}