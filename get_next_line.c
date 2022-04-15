/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:23 by bperron           #+#    #+#             */
/*   Updated: 2022/04/15 10:45:21 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buffer;
    char hold;
    int i;
    int stop;
    
    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return (NULL);
    if(fd < 2)
    {
        free(buffer);
        return (NULL);
    }
    hold = 0;
    i = 0;
    stop = 1;
    stop = read(fd, &hold, 1);
    if (stop <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i++] = hold;
    while (hold != '\n' && stop == 1)
    {
        stop = read(fd, &hold, 1);
        if (stop == 1)
            buffer[i++] = hold;
        else if (stop == 0)
        {
            buffer[i] = '\0';
            return (buffer);
        }
    }
    buffer[i] = '\0';
    return (buffer);
}