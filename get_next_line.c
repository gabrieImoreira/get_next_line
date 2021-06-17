/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/17 19:56:49 by gantonio         ###   ########.fr       */
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

// static char *ft_return_new_line(void *str)
// {
	
// }

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
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);

	if (!repository)
		repository = malloc(sizeof(char) * BUFFER_SIZE + 1);
	repository = ft_strjoin(repository, buf);
	
	if(ft_strchr(repository, '\n')){
		while (repository[++len] != '\n' && len <= BUFFER_SIZE)
	 		new_line[len] = repository[len];
	}
	//printf("nl:%s\n\n", new_line);
	while (repository[len++])
		temp[i++] = repository[len];
	ft_bzero(repository, ft_strlen(repository));
	repository = ft_strjoin(repository, temp);
	
	//printf("\n\nrp:%s\n", repository);
	*line = new_line;
	//*line = repository;
	//*line = temp;

	return(ret);
}