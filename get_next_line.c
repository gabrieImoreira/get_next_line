/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:17:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/16 22:44:52 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int ret;
	char *buf;
	size_t len;
	char *temp;
	static char *repository;
	
	len = -1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = read(fd, buf, BUFFER_SIZE);
	repository = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	//repository = 
	while (buf[++len] != '\n')
	 	repository[len] = buf[len];
	// while (buf[len])
	// {
	// 	repository[len] = buf[len];
	// 	len++;
	// }
	
	*line = repository;

	return(ret);
}