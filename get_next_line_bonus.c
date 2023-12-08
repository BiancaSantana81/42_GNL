/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:36:49 by bsantana          #+#    #+#             */
/*   Updated: 2023/12/05 14:15:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*bytes_read] = '\0';
	return (buffer);
}

char	*remaining(char *str)
{
	char	*remaining_buffer;
	char	*position_n;

	remaining_buffer = ft_strchr(str, '\n');
	if (remaining_buffer == NULL || remaining_buffer[1] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (remaining_buffer[0] == '\0')
	{
		free(remaining_buffer);
		return (NULL);
	}
	position_n = ft_strdup(remaining_buffer + 1);
	free(str);
	return (position_n);
}

void	check_bytes_read(ssize_t bytes_read, char **line)
{
	if (bytes_read < 0)
	{
		free(*line);
		*line = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 0;
	line = NULL;
	if (buffer[fd])
	{
		line = ft_strjoin(NULL, buffer[fd]);
		if (!ft_strchr(buffer[fd], '\n'))
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
	}
	while ((!ft_strchr(buffer[fd], '\n')))
	{
		buffer[fd] = read_file(fd, buffer[fd], &bytes_read);
		if (!buffer[fd])
			break ;
		line = ft_strjoin(line, buffer[fd]);
	}
	check_bytes_read(bytes_read, &line);
	buffer[fd] = remaining(buffer[fd]);
	return (line);
}

size_t	find_n(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}
