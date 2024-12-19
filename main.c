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

#include "get_next_line.h"

int main(int ac, char **av)
{
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