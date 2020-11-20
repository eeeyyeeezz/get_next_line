/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:58:22 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/20 16:51:54 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

static int			ft_return_neg(char *buf)
{
	free(buf);
	buf = NULL;
	return (-1);
}

static char			*check_remainer(char **remainer, char **line)
{
	char *ptr;

	*line = NULL;
	ptr = NULL;
	if (*remainer)
		if ((ptr = ft_strchr(*remainer, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(*remainer);
			if (ptr == NULL)
				ft_strclr(&(*remainer));
			else
				ft_strcpy(*remainer, ++ptr);
		}
		else
		{
			*line = ft_strdup(*remainer);
			free(*remainer);
			remainer = NULL;
		}
	else
		*line = ft_strdup("");
	return (ptr);
}

static int			ft_return(int byte_read, char **remainer,
					char *ptr, char *buf)
{
	free(buf);
	if (byte_read == 0)
		*remainer = ft_strdup("");
	if (ptr == NULL)
		return (0);
	else
		return (1);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	char			*ptr;
	char			*tmp;
	static	char	*remainer[1024];
	int				byte_read;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !(buf = malloc(BUFFER_SIZE + 1))
		|| (-1 == read(fd, buf, 0)))
		return (ft_return_neg(buf));
	ptr = check_remainer(&remainer[fd], line);
	while (!ptr && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			if (!(remainer[fd] = ft_strdup(++ptr)))
				return (ft_return_neg(buf));
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)))
			return (ft_return_neg(buf));
	}
	return (ft_return(byte_read, &remainer[fd], ptr, buf));
}
