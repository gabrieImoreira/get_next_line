/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:41:34 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/22 17:56:22 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static int	ft_read_and_join(int fd, char **repository, char *buf)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_is_new_line(*repository) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (GNL_ERROR);
		buf[bytes_read] = '\0';
		*repository = ft_strjoin(*repository, buf);
	}
	return (bytes_read);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	long int	bytes_read;
	static char	*repository[FD_SETSIZE];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (GNL_ERROR);
	bytes_read = ft_read_and_join(fd, &repository[fd], buf);
	free(buf);
	if (bytes_read == -1)
		return (GNL_ERROR);
	*line = ft_return_new_line(repository[fd]);
	repository[fd] = ft_fix_repository(repository[fd]);
	if (bytes_read == 0)
		return (GNL_EOF);
	return (GNL_LINEBREAK);
}
