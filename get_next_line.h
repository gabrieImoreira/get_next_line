#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
int		ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif