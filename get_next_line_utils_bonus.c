/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:25 by bsantana          #+#    #+#             */
/*   Updated: 2023/12/05 14:17:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	i;

	i = c;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == i)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char		*dest;
	size_t		size;
	size_t		i;

	i = 0;
	size = ft_strlen(s);
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;
	size_t		s1_len;
	size_t		find_n_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	find_n_len = find_n(s2);
	result = malloc (((s1_len + find_n_len + 1)) + 1 * sizeof(char));
	if (!result)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (j <= find_n_len)
		result[i++] = s2[j++];
	result[(s1_len + find_n_len + 1)] = '\0';
	free(s1);
	s1 = NULL;
	return (result);
}
