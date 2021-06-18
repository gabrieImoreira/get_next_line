/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/18 00:19:01 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_bzero(void *str, size_t len)
{
	char	*ptr;

	ptr = str;
	while (len--)
		*ptr++ = '\0';
}

static char	*ft_return_new_line(int fd, char *buf, char *repository, int *ret)
{
	int		is_new_line;
	size_t	len;
	int		bytes_read;
	char	*new_line;
	char	*temp;
	int		i;

	i = 0;
	is_new_line = 1;
	len = -1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (is_new_line)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		repository = ft_strjoin(repository, buf);
		if (ft_strchr(repository, '\n') || bytes_read <= 0)
			is_new_line = 0;
	}
	while (repository[++len] != '\n' && repository[len])
		new_line[len] = repository[len];
	new_line[len] = '\0';
	while (repository[++len])
		temp[i++] = repository[len];
	ft_bzero(repository, ft_strlen(repository));
	repository = ft_strjoin(repository, temp);
	free(temp);
	*ret = bytes_read;
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	char		*new_line;
	int			*ret;
	static char	*repository;

	ret = malloc(sizeof(int));
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!repository)
		repository = malloc(sizeof(char) * BUFFER_SIZE + 1);
	*line = ft_return_new_line(fd, buf, repository, ret);
	return (1);
}
