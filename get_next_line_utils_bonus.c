/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:21 by bperron           #+#    #+#             */
/*   Updated: 2022/05/12 13:32:31 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *ptr, size_t n)
{
	int				i;

	i = 0;
	while (n-- > 0)
		((char *) ptr)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return ((void *) ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	size_t	len;

	str = (char *) s;
	len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	while (len-- > 0)
	{
		if (str[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}
