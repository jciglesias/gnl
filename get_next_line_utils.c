/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:56:23 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/12 16:41:53 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i++]);
	return (i);
}

static char		*ft_strdup(char *s)
{
	int			i;
	char		*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = (char)s[i];
	dup[i] = 0;
	return (dup);
}

void	ft_realloc(char *bowl)
{
	char	*dup;
	int		i;

	i = -1;
	dup = ft_strdup(bowl);
	bowl = (char *)malloc(sizeof(char) * (ft_strlen(dup) + BUFFER_SIZE + 1));
	while (dup[++i])
		bowl[i] = dup[i];
	bowl[i] = 0;
	free(dup);
}
