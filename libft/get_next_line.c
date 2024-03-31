/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos- <gcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:41:22 by gcampos-          #+#    #+#             */
/*   Updated: 2024/03/31 14:34:49 by gcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_read_txt(int fd, char *str)
{
	char	*buffer;
	int		qtd_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	qtd_bytes = 1;
	while (!get_strchr(str, '\n') && qtd_bytes != 0)
	{
		qtd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (qtd_bytes == -1 || !buffer)
		{
			free(buffer);
			buffer = NULL;
			free(str);
			return (NULL);
		}
		buffer[qtd_bytes] = '\0';
		str = get_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read_txt(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = keep_rest(str);
	return (line);
}
