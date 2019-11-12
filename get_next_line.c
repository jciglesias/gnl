/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:43:51 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/12 16:48:16 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_cutline(char *spoon[BUFFER_SIZE], char *bowl)
{
	int i;
	int j;
	int a;

	i = -1;
	j = 0;
	a = 1;
	while (bowl[j++]);
	while (spoon[++i])
	{
		bowl[j++] = *spoon[i];
		if (*spoon[i] == '\n')
			a = 0;
	}
	bowl[j] = 0;
	return (a);
}

int		get_next_line(int fd, char **line)
{
	char			*spoon[BUFFER_SIZE];
	static char		*bowl;
	int				i;
	int				j;

	bowl = NULL;
	i = 0;
	j = 0;
	if (fd >= 0)
	{
		while (read(fd, &spoon, BUFFER_SIZE) > 0)
		{
			ft_realloc(bowl);
			if (!ft_cutline(spoon, bowl))
				break ;
		}
		while (bowl[i])
		{
			*line[j++] = bowl[i++];
			if (!bowl[i] || bowl[i] == '\n')
			{
				bowl = &bowl[++i];
				**line++ = 0;
				return (1);
			}
		}
		return (0);
	}
	return (-1);
}
