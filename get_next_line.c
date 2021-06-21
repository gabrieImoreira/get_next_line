/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:41:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/21 19:28:26 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_repository(char *str)
{
	char	*repo;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	repo = malloc(sizeof(char) * ((ft_strlen(str) - len) + 1));
	if (!repo)
		return (0);
	while (str[++len])
		repo[i++] = str[len];
	repo[i] = '\0';
	free(str);
	return (repo);
}

static char	*ft_return_new_line(char *str)
{
	int		len;
	char	*new_line;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (NULL);
	len = -1;
	while (str[++len] && str[len] != '\n')
		new_line[len] = str[len];
	new_line[len] = '\0';
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	long int			bytes_read;
	static char	*repository;

	bytes_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	while (!ft_is_new_line(repository) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (GNL_ERROR);
		buf[bytes_read] = '\0';
		repository = ft_strjoin(repository, buf);
	}
	*line = ft_return_new_line(repository);
	repository = ft_fix_repository(repository);
	if (bytes_read == 0)
		return (GNL_EOF);
	return (GNL_LINEBREAK);
}
