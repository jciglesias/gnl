/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:43:51 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/28 12:25:58 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_fillbowl(char spoon[BUFFER_SIZE + 1], char *bowl)
{
	size_t		i;
	size_t		j;
	int			a;

	i = 0;
	j = BUFFER_SIZE;
	a = 1;
	while (spoon[i])
	{
		bowl[i] = spoon[i];
		if (spoon[i] == '\n' || (!spoon[i + 1] && j))
			a = 0;
		i++;
		j--;
	}
	bowl[i] = 0;
	return (a);
}

int		ft_newline(char **line, char *bowl)
{
	int		i;
	size_t	j;

	i = 0;
	j = BUFFER_SIZE;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(bowl) + 1))))
		return (-1);
	while (bowl[i])
	{
		(*line)[i] = bowl[i];
		(*line)[++i] = 0;
		j--;
		if (!bowl[i] && j)
		{
			if (bowl)
				free(bowl);
			return (0);
		}
		if (bowl[i - 1] == '\n')
		{
			ft_scrapbowl(bowl);
			return (1);
		}
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			spoon[BUFFER_SIZE + 1];
	static char		*bowl;
	int				j;

	if (fd >= 0 && line)
	{
		if (!(bowl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		bowl[0] = 0;
		while ((j = read(fd, spoon, BUFFER_SIZE)) > 0)
		{
			spoon[j] = 0;
			if (!(ft_fillbowl(spoon, bowl)))
				break ;
			if (!(bowl = ft_realloc(bowl)))
				return (-1);
		}
		int a;
		a = ft_newline(line, bowl);
		//printf("%s\n", *line);
		return (a);
	}
	return (-1);
}
