/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:22:48 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/18 21:09:21 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *str)
{
	char *dup_str;
	char *p;

	dup_str = malloc(ft_strlen(str) + 1);
	p = dup_str;
	if (dup_str == NULL)
		return (NULL);
	while (*str)
		*(p++) = *(str++);
	*p = '\0';
	return (dup_str);
}

size_t		ft_strlen(const char *s)
{
	int a;

	a = 0;
	while (s[a] != 0)
		a++;
	return (a);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*free_ptr;
	char	*new_string;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	free_ptr = (char *)s1;
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (*s1)
		new_string[i++] = *s1++;
	while (*s2)
		new_string[i++] = *s2++;
	new_string[i] = '\0';
	free(free_ptr);
	return (new_string);
}

char		*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
