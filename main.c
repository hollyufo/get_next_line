/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:09:41 by imchaibi          #+#    #+#             */
/*   Updated: 2024/12/15 18:23:32 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 42

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 42

// A helper function to read the content into the buffer and handle remainder
ssize_t gnl_buff(char *buffer, char *remainder, int fd) {
    // If remainder has data from previous read, use it and reset remainder
    if (remainder[0] != '\0') {
        strcpy(buffer, remainder);
        remainder[0] = '\0';
        return strlen(buffer);  // Return the length of the data copied into buffer
    }

    bzero(buffer, BUFFER_SIZE + 1);
    return read(fd, buffer, BUFFER_SIZE);  // Read new data into the buffer
}

// A helper function to join strings safely
char *ft_strjoin(char *s1, char *s2) {
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = strlen(s2);
    char *new_str = malloc(len1 + len2 + 1);
    if (!new_str) return NULL;

    if (s1) {
        strcpy(new_str, s1);
        free(s1);  // Free the old string after copying
    }
    strcpy(new_str + len1, s2);
    return new_str;
}

char *get_next_line(int fd) {
    
    int bytes_read;
    char buffer[BUFFER_SIZE + 1];
    static char remainder[BUFFER_SIZE + 1] = {0};
    char *line = NULL;

    while (1) {
        bytes_read = gnl_buff(buffer, remainder, fd);
        if (bytes_read <= 0) {
            return line;  // Return any remaining line or NULL
        }
        char *nl = strchr(buffer, '\n');
        if (nl) {
            *nl = '\0';
            line = ft_strjoin(line, buffer);
            strcpy(remainder, nl + 1);
            
            return line;
        }
        line = ft_strjoin(line, buffer);
    }
}

int main(int ac, char **av) {
    if (ac != 2) return 0;

    int fd = open(av[1], O_RDONLY);
    if (fd == -1) return 0;

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf(">>>%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}