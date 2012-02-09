#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define TAILLE_BUFF 80

void get_section(int fd)
{
		 
}
void get_name(int fd, 
void get_value
int main (int argc, char ** argv) {
	int fd;
	char buff[TAILLE_BUFF];	
	int count = 0;

	fd = open("../config.ini", O_RDONLY);
    if (fd == -1)
    {
		perror("Error : file config");
		return 1;
    }

	while ((count = read(fd, buff, TAILLE_BUFF)) > 0)
    {
		printf("%s", buff);
	}
	if ((count = read(fd, buff, TAILLE_BUFF)) == -1)
	{
		perror("Error : read");
    	return 1;
	}
	close(fd);
	return 0;
}

