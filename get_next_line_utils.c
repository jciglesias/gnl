/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:56:23 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/17 18:59:42 by jiglesia         ###   ########.fr       */
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

char		*ft_strdup(char *s)
{
	int			i;
	char		*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	//printf("\nstrdup\n");
	i = -1;
	while (s[++i])
		dup[i] = (char)s[i];
	dup[i] = 0;
	return (dup);
}

char			*ft_realloc(char *bowl)
{
	char	*dup;
	int		i;

	i = -1;
	if (!bowl)
	{
		if (!(bowl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (NULL);
		bowl[0] = 0;
		return (bowl);
	}
	dup = ft_strdup(bowl);
	//	printf("\nrealloc\n");
	free(bowl);
	if (!(bowl = (char *)malloc(sizeof(char) * (ft_strlen(dup) + BUFFER_SIZE + 1))))
		return (NULL);
	while (dup[++i])
		bowl[i] = dup[i];
	bowl[i] = 0;
	free(dup);
	return (bowl);
}
