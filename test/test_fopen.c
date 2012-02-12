#include <stdio.h>

int main(int argc, char ** argv)
{
    FILE * file;
    file = fopen(argv[1], argv[2]);
    if (file == NULL)
    {
        perror("Open file");
        return 1;
    }
    printf("Open file %s, mode %s\n", argv[1], argv[2]);
    fclose(file);
    return 0;
}
