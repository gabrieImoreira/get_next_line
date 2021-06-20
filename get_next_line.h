#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_is_new_line(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif