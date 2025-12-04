#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int main()
{

	int fd;

	fd = open("get_next_line.h", O_RDONLY | O_CREAT);
	char *buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}

	free(buffer);
}
