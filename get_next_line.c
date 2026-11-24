/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:29:20 by omejri            #+#    #+#             */
/*   Updated: 2026/11/24 18:58:42 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char container[10000000000];
    char over[10000000000];
    int i;
    int j;

    i = 0;
    j = 0;
    while(container[i])
    {
        if (container[i] == '\n')
        {
            write(1,container,i);
            i++;
            while(container[i])
            {
                container[j] = container[i];
                i++;
                j++;
            }
            return(1);
        }
        i++;
    }
    i = read(fd,container,10);
    if (i == 0)
    {
        while(container[i])
        {
            write(1,container + i,1);
            i++;
        }
        return(1);
    }
    else if (i > 0)
    {
        i = 0;
        while(container[i])
        {
            if (container[i] == '\n')
            {
                write(1,container,i);
                i++;
                while(container[i])
                {
                    container[j] = container[i];
                    i++;
                    j++;
                }
                return(1);
            }
            i++;
        }
    }
    else if (i == -1)
        return(0);
    return(-1);
}