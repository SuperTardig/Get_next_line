/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:23 by bperron           #+#    #+#             */
/*   Updated: 2022/04/28 14:47:46 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *stat, char *buffer, int stop)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(stat);
	i += ft_strlen(buffer);
	new = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (stat[i])
	{
		new[i] = stat[i];
		i++;
	}
	while (buffer[j])
		new[i++] = buffer[j++];
	if (stop < BUFFER_SIZE)
		new[i++] = '\n';
	new[i] = '\0';
	free(stat);
	return (new);
}

char	*ft_fill_buffer(char *stat, int fd)
{
	char	*buffer;
	int		stop;

	if (!stat)
		stat = ft_calloc(1, 1);
	stop = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (stop > 0)
	{
		stop = read(fd, buffer, BUFFER_SIZE);
		if (stop < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (stop == 0)
			break ;
		stat = ft_join(stat, buffer, stop);
		if (ft_strchr(stat, '\n') == 1)
			break ;
	}
	free (buffer);
	return (stat);
}

char	*ft_fill_line(char *stat, char *old)
{
	char	*line;
	int		i;

	i = 0;
	if (!stat)
		return (NULL);
	while (stat[i] && stat[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (stat[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	free(old);
	return (line);
}

char	*ft_del_old(char *stat)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (stat)
	{
		while (stat[i] && stat[i] != '\n')
			i++;
		i++;
		new = ft_calloc(ft_strlen(stat) - i + 2, sizeof(char));
		while (stat[i])
			new[j++] = stat[i++];
		new[j] = '\0';
	}
	else
		new = NULL;
	free(stat);
	return (new);
}

char	*get_next_line(int fd)
{
	static char		*stat[OPEN_MAX];
	char			*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat[fd] = ft_fill_buffer(stat[fd], fd);
	line = ft_fill_line(stat[fd], line);
	stat[fd] = ft_del_old(stat[fd]);
	return (line);
}
