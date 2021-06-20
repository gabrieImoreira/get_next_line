#include "get_next_line.h"
#include <stdio.h>

char	*ft_clean_repository(char *str)
{
	char	*repo;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (!str[len])
	{
		free(str);
		return (0);
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
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	new_line = malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (0);
	len = -1;
	while (str[++len] && str[len] != '\n')
		new_line[len] = str[len];
	new_line[len] = '\0';
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	static char	*repository;

	bytes_read = 1;
	if (fd < 0 || !line)
		return (-1);
	while (!ft_is_new_line(repository) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buf[bytes_read] = '\0';
		repository = ft_strjoin(repository, buf);
	}
	*line = ft_return_new_line(repository);
	repository = ft_clean_repository(repository);
	if (bytes_read == 0)
		return (0);
	return (1);
}
