#include "get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{


	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char *str = "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";	fd = open("numbers", O_RDONLY);
	char **ptr;
	ptr = &str;
	while(ret = read(fd, buf, BUF_SIZE))
	{
		ft_putstr_fd("OK!\n", 1);
		ft_putstr_fd(buf, 1);
	}
	printf("\n**********************\n");
	if(fd == -1)
		ft_putstr_fd("error\n", 0);
	ret = read(fd, buf, BUF_SIZE);
	ft_putstr_fd(buf, 1);

}