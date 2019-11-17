/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:43:51 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/17 19:06:09 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_fillbowl(char spoon[BUFFER_SIZE + 1], char *bowl)
{
	size_t		i;
	size_t		j;
	int			a;

	i = 0;
	j = ft_strlen(bowl);
	a = 1;
	//	printf("\ncutline\n");
	while (spoon[i])
	{
		bowl[j++] = spoon[i];
		if (spoon[i++] == '\n')
			a = 0;
	}
	bowl[j] = 0;
	return (a);
}

char	*ft_scrapbowl(char *bowl)
{
	char	*dup;
	int		i;

	i = 0;
	while (bowl[i] && bowl[i] != '\n')
		i++;
	while (bowl[i] && bowl[i] == '\n')
		i++;
	dup = ft_strdup(&bowl[i]);
	free(bowl);
	return (dup);
}

int		ft_cpyline(char *line, char *bowl)
{
	int i;

	i = 0;
	if (!bowl)
		return (0);
	if (!(line = (char *)malloc(sizeof(char) * (ft_strlen(bowl) + 1))))
		return (-1);
	while (bowl[i])
	{
		line[i] = bowl[i];
		if (bowl[++i] == '\n')
		{
			bowl = ft_scrapbowl(bowl);
			line[i] = 0;
			return (1);
		}
		if (!bowl[i])
		{
			free(bowl);
			line[i] = 0;
			return (0);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			spoon[BUFFER_SIZE + 1];
	static char		*bowl;
	int				i;
	int				j;

	i = 0;
	if (fd >= 0)
	{
		while ((j = read(fd, &spoon, BUFFER_SIZE)) > 0)
		{
			spoon[j] = 0;
			if (!(bowl = ft_realloc(bowl)))
				return (-1);
			if (ft_fillbowl(spoon, bowl) == 0)
				return (ft_cpyline(*line, bowl));
		}
		//printf("\nhola\n");
		return (ft_cpyline(*line, bowl));
	}
	return (-1);
}
