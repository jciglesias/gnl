/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:43:51 by jiglesia          #+#    #+#             */
/*   Updated: 2020/01/17 18:38:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_scrapbowl(char *bowl)
{
	char		*dup;

	dup = ft_strdup(ft_strchr(bowl, '\n') + 1);
	if (bowl)
		free(bowl);
	return (dup);
}

void			*ft_finalfree(char *bowl)
{
	free(bowl);
	return (NULL);
}

int				ft_fillbowl(char spoon[BUFFER_SIZE + 1], char *bowl)
{
	size_t		i;
	size_t		j;
	int			a;

	i = 0;
	j = ft_strlen(bowl);
	a = 1;
	while (spoon[i])
	{
		bowl[j + i] = spoon[i];
		if (spoon[i] == '\n')
			a = 0;
		i++;
	}
	bowl[j + i] = 0;
	return (a);
}

int				ft_newline(char **line, char *bowl, size_t j)
{
	size_t	i;

	i = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(bowl) + 1))))
		return (-1);
	(*line)[0] = 0;
	while (bowl[i])
	{
		(*line)[i] = bowl[i];
		(*line)[++i] = 0;
		if (!bowl[i] && j == 0)
		{
			return (0);
		}
		if (bowl[i - 1] == '\n')
			return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			spoon[BUFFER_SIZE + 1];
	static char		*bowl;
	size_t			j;
	int				a;

	if (fd >= 0 && line)
	{
		if (!bowl)
		{
			if (!(bowl = (char *)malloc(sizeof(char))))
				return (-1);
			bowl[0] = 0;
		}
		while ((j = read(fd, spoon, BUFFER_SIZE)) > 0)
		{
			spoon[j] = 0;
			if (!(bowl = ft_realloc(bowl)))
				return (-1);
			if (!(ft_fillbowl(spoon, bowl)))
				break ;
		}
		if ((a = ft_newline(line, bowl, j)) == 1)
			bowl = ft_scrapbowl(bowl);
		if (a == 0)
			bowl = ft_finalfree(bowl);
		return (a);
	}
	return (-1);
}
