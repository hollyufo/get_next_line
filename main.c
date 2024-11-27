/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hollyufo <hollyufo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:41 by imchaibi          #+#    #+#             */
/*   Updated: 2024/11/27 15:26:43 by hollyufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


char	*get_next_line(int fd)
{
	
}

int main(void)
{
   int fd;
    char buffer[1]; // Buffer to hold one byte of data

    // Open the file in read-only mode
    fd = open("yourfile.txt", O_CREAT);
    
    if (fd == -1) {
        perror("Could not open file");
        return 1;
    }

    // Read characters until the end of the file or newline is encountered
    while (read(fd, buffer, 1) > 0) {
        write(STDOUT_FILENO, buffer, 1);  // Print the character to stdout

        // Stop printing if a newline character is encountered
        if (buffer[0] == '\n') {
            break;
        }
    }

    // Close the file
    close(fd);

    return 0;
}