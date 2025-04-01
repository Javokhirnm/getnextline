/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:42:51 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 18:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int search_str);
char	*get_line(char *s);
char	*storage_update(char *storage);

char	*get_line(char *s)
{
	size_t	i;
	char	*line;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*combine(char *s1, char *temp_buffer)
{
	char	*res;

	if (!s1 && !temp_buffer)
		return (NULL);
	if (!s1)
		return (ft_strdup(temp_buffer));
	if (!temp_buffer)
		return (ft_strdup(s1));
	res = ft_strjoin(s1, temp_buffer);
	free(s1);
	return (res);
}

char	*free_everything(char *storage, char *temp_buffer)
{
	free(storage);
	free(temp_buffer);
	return (NULL);
}

char	*reading(int fd, char *storage)
{
	char	*temp_buffer;
	int		bytes_read;

	if (!storage)
		storage = ft_strdup("");
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (free_everything(storage, NULL));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_everything(storage, temp_buffer));
		temp_buffer[bytes_read] = '\0';
		storage = combine(storage, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = reading(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = storage_update(buffer);
	return (line);
}