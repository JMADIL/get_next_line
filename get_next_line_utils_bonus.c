/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:50:08 by ajamoun           #+#    #+#             */
/*   Updated: 2024/12/19 06:01:57 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (x);
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	i = 0; 
	dest = malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strs;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		ft_strdup(s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = -1;
	strs = malloc(i + j + 1);
	if (!strs)
		return (free(s1), s1 = NULL, NULL);
	while (s1[++k])
		strs[k] = s1[k];
	k = -1;
	while (s2[++k])
		strs[i + k] = s2[k];
	strs[i + j] = '\0';
	free(s1);
	return (strs);
}
