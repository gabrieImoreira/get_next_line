/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/20 14:37:49 by gantonio         ###   ########.fr       */
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
	int i;
	
	len = 0;
	bytes_read = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!temp)
		return (NULL);
	if(!new_line)
		return (NULL);
	while (!ft_is_new_line(repository) && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		ft_strlcat(repository, buf, ft_strlen(buf) + ft_strlen(repository) + 1);
		//printf("\nstrlcpy -> rep end: |%s|", repository);
	}
	repository[ft_strlen(repository) + 1];
	free(buf);
	printf("\nrep FORA: |%s|", repository);
	if(!repository)
		return (0);
	while (repository[len] != '\n' && repository[len])
		len++;
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!new_line)
		return (0);
	len = -1;
	while (repository[++len] != '\n' && repository[len])
		new_line[len] = repository[len];
	new_line[len] = '\0';
	*ret = bytes_read;
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	char		*new_line;
	int			*ret;
	static char	repository[BUFFER_SIZE + 1];

	ret = malloc(sizeof(int));
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
		return (-1);
	*line = ft_return_new_line(fd, buf, repository, ret);
	if(ret > 0)
		return (1);
	else if(ret < 0)
		return (-1);
	else
		return (0);
}
