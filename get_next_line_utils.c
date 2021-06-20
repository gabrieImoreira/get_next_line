/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:54:10 by gantonio          #+#    #+#             */
/*   Updated: 2021/06/20 14:37:27 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen((char *)src);
	dest = malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_new_line(const char *str)
{
	size_t	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	d;
	unsigned int	j;
	unsigned int	i;
	unsigned int	s;

	i = 0;
	s = ft_strlen(src);
	d = ft_strlen(dest);
	j = s + d;
	if (size > d)
	{
		while (d + 1 < size && src[i] != '\0')
		{
			dest[d] = src[i];
			i++;
			d++;
		}
		dest[d] = '\0';
		return (j);
	}
	if (size == d)
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + size);
}
