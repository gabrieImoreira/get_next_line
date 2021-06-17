/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/16 23:50:28 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	ft_bzero(void *str, size_t len)
{
	char	*ptr;

	ptr = str;
	while (len--)
		*ptr++ = '\0';
}

int get_next_line(int fd, char **line)
{
	int ret;
	char *buf;
	size_t len;
	char *new_line;
	char *temp;
	static char *repository;
	int i;
	
	len = -1;
	i = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = read(fd, buf, BUFFER_SIZE);
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	temp = malloc(sizeof(char) * BUFFER_SIZE - len + 1);

	if(!repository)
		repository = malloc(sizeof(char) * BUFFER_SIZE + 1);
	repository = ft_strjoin(repository, buf);
	
	while (repository[++len] != '\n')
	 	new_line[len] = repository[len];
	while (repository[len++] && len < BUFFER_SIZE)
		temp[i++] = repository[len];
	ft_bzero(repository, ft_strlen(repository));
	repository = ft_strjoin(repository, temp);
	
	*line = new_line;
	//*line = repository;
	//*line = temp;

	return(ret);
}