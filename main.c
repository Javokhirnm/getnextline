/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:44:08 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 18:44:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    char *string;
    char *string2;
    char *string3;
    int i;

    i = 0;
    int fd = open("read_from.txt", O_RDONLY);
    // printf("original fd %d\n\n\n", fd);
    if (fd < 0)
    {
        perror("Error");
        return 1;
    }
    while (i < 10)
    {
        string = get_next_line(fd);
        printf("Result : %s\n", string);
        i++;
    }
    close(fd);
    return (0);
}