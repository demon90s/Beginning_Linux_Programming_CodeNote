/*
 * read （p83）
 * 从与文件描述符 fildes 相关联的文件里读入 nbytes 个字节的数据，并把它们放到数据区 buf 中。
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 例子，读取整个文件的内容
 */
void example_read_file()
{
	char buffer[128];
	int nread;
	int fd;

	fd = open("./api_read.c", O_RDONLY);
	if (fd == -1) {
		perror("open");
		return;
	}

	memset(buffer, 0, sizeof(buffer));
	nread = read(fd, buffer, sizeof(buffer) - 1);
	
	while (nread > 0) {
		printf("%s", buffer);
		
		memset(buffer, 0, sizeof(buffer));
		nread = read(fd, buffer, sizeof(buffer) - 1);
	}

	close(fd);
}


int main()
{
	example_read_file();

	exit(EXIT_SUCCESS);
}
