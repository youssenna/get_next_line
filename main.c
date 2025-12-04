#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int main()
{

	int fd;

	fd = open("text.txt", O_RDONLY | O_CREAT);
	char *buffer = get_next_line(fd);
	while (buffer)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}

	free(buffer);
}
