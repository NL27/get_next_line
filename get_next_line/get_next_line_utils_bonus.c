/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:03:41 by nlenoch           #+#    #+#             */
/*   Updated: 2021/09/22 17:03:42 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	if (c == NULL)
		return (0);
	while (*c != '\0')
	{
		count++;
		c++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sj = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (sj == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		sj[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		sj[i] = s2[x];
		i++;
		x++;
	}
	sj[i] = '\0';
	return (sj);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	index;
	size_t	extract;
	char	*substr;

	index = 0;
	while (index < start)
	{
		if (s[index] == '\0')
			return (ft_strdup(""));
		index++;
	}
	extract = ft_strlen(s + index);
	if (len < extract)
		extract = len;
	substr = malloc(sizeof(char) * (extract + 1));
	i = 0;
	while (i < extract)
	{
		substr[i] = s[index + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
