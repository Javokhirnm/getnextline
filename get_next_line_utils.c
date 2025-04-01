/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:43:52 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 18:43:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s);

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	size;
	char	*new_str;

	i = 0;
	size = ft_strlen(s);
	new_str = malloc((size + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*new_str;

	i = 0;
	k = 0;
	new_str = malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		new_str[i] = s2[k];
		i++;
		k++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_str)
			return ((char *)&str[i]);
		i++;
	}
	if (search_str == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*storage_update(char *storage)
{
	char	*updated_storage;
	int		i;
	int		k;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	updated_storage = malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!updated_storage)
		return (NULL);
	k = 0;
	while (storage[i] != '\0')
		updated_storage[k++] = storage[i++];
	updated_storage[k] = '\0';
	free(storage);
	return (updated_storage);
}