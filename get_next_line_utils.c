/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekomarga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:28:30 by ekomarga          #+#    #+#             */
/*   Updated: 2026/09/02 19:00:49 by ekomarga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *leftover, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!leftover)
	{
		leftover = (char *)malloc(1 * sizeof(char));
		if (!leftover)
			return (NULL);
		leftover[0] = '\0';
	}
	if (!buffer)
		return (free(leftover), NULL);
	new_str = malloc(ft_strlen(leftover) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(leftover), NULL);
	i = -1;
	while (leftover[++i])
		new_str[i] = leftover[i];
	j = -1;
	while (buffer[++j])
		new_str[i + j] = buffer[j];
	new_str[i + j] = '\0';
	free (leftover);
	return (new_str);
}
