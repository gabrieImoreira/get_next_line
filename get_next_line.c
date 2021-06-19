/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/19 00:34:45 by gantonio         ###   ########.fr       */
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
	int		len;
	int		bytes_read;
	char	*new_line;
	char	*temp;
	int		i;

	i = 0;
	len = -1;
	is_new_line = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!new_line)
		return (NULL);
	while (is_new_line)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		//printf("\nstrlcpy -> rep init: |%s|", repository);
		ft_strlcat(repository, buf, ft_strlen(buf) + ft_strlen(repository) + 1);
		//printf("\nstrlcpy -> rep end: |%s|", repository);
		if (ft_strchr(repository, '\n') || bytes_read <= 0)
			break;
	}
	//printf("\nrep FORA: |%s|", repository);
	//printf("%d", len);
	while (repository[++len] != '\n' && repository[len])
	{
		printf(",%c", new_line[len]);
		new_line[len] = repository[len];
	}
	new_line[len] = '\0';
	printf("\nnew line: |%s|\n", new_line);
	while (repository[++len])
		temp[i++] = repository[len];
	ft_bzero(repository, ft_strlen(repository));
	ft_strlcat(repository, temp, ft_strlen(repository) + ft_strlen(temp) + 1);
	free(temp);
	//printf("\nrep end: %s\n\n", repository);
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
	if(ret > 0)
		return (1);
	else if(ret < 0)
		return (-1);
	else
		return (0);
}
