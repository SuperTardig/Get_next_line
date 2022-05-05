/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperron <bperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:24:25 by bperron           #+#    #+#             */
/*   Updated: 2022/05/05 11:02:32 by bperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_fill_buffer(char *stat, int fd);
char	*ft_join(char *stat, char *buffer, int stop);
char	*ft_del_old(char *stat);
char	*ft_fill_line(char *stat);

#endif
