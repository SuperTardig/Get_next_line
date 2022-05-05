/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:23 by bperron           #+#    #+#             */
/*   Updated: 2022/05/05 11:02:45 by bperron          ###   ########.fr       */
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
	if (!new)
	{
		free (stat);
		return (NULL);
	}
	i = 0;
	while (stat[i])
	{
		new[i] = stat[i];
		i++;
	}
	while (buffer[j] && stop-- > 0)
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(stat);
	return (new);
}

char	*ft_fill_buffer(char *stat, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		stop;

	if (!stat)
	{
		stat = ft_calloc(1, 1);
		if (!stat)
			return (NULL);
	}
	stop = 1;
	while (ft_strchr(stat, '\n') == 0 && stop > 0)
	{
		stop = read(fd, buffer, BUFFER_SIZE);
		if (stop < 0)
			return (NULL);
		stat = ft_join(stat, buffer, stop);
	}
	return (stat);
}

char	*ft_fill_line(char *stat)
{
	char	*line;
	int		i;

	i = 0;
	if (!stat)
		return (NULL);
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (stat[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_del_old(char *stat)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (stat[i])
	{
		while (stat[i] && stat[i] != '\n')
			i++;
		i++;
		new = ft_calloc(ft_strlen(stat) - i + 2, sizeof(char));
		if (!new)
			return (NULL);
		while (stat[i])
			new[j++] = stat[i++];
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

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat[fd] = ft_fill_buffer(stat[fd], fd);
	line = ft_fill_line(stat[fd]);
	stat[fd] = ft_del_old(stat[fd]);
	return (line);
}
