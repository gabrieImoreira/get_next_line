#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUF_SIZE
#define BUF_SIZE 10
#endif

# include <unistd.h>
# include <stdlib.h>

int get_next_line(int fd, char **line);

#endif