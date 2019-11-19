/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:56:23 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/19 16:42:38 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i++]);
	return (i);
}

char	*ft_strdup(char *s)
{
	int			i;
	char		*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	//printf("\nstrdup\n");
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = 0;
	return (dup);
}

char	*ft_realloc(char *bowl)
{
	char		*dup;
	int			i;

	i = -1;
	dup = ft_strdup(bowl);
	//printf("\nrealloc\n");
	if (bowl)
		free(bowl);
	if (!(bowl = (char *)malloc(sizeof(char) * (ft_strlen(dup) + BUFFER_SIZE + 1))))
		return (NULL);
	while (dup[++i])
		bowl[i] = dup[i];
	bowl[i] = 0;
	if (dup)
		free(dup);
	return (bowl);
}

char	*ft_scrapbowl(char *bowl)
{
	char		*dup;
	int			i;

	i = 0;
	while (bowl[i] && bowl[i] != '\n')
		i++;
	while (bowl[i] && bowl[i] == '\n')
		i++;
	dup = ft_strdup(&bowl[i]);
	//printf("scrap");
	if (bowl)
		free(bowl);
	return (dup);
}
