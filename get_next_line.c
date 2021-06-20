/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/20 16:57:46 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_update_buffer(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}
static char	*ft_return_new_line(int fd, char *buf, char *repository, int *ret)
{
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
		repository = ft_strjoin(repository, buf);
		//printf("\nstrlcpy -> rep end: |%s|", repository);
	}
	repository[ft_strlen(repository) + 1] = '\0';
	free(buf);
	//printf("\nrep FORA: |%s|\n", repository);
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
	//printf("\nrep FORA: |%s|\n", repository);
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
	*line = ft_return_new_line(fd, buf, &repository, ret);
	//printf("\nrep FORA: |%s|\n", repository);
	if(ret > 0)
		return (1);
	else if(ret < 0)
		return (-1);
	else
		return (0);
}
