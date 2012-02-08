#include <stdio.h>
#include <string.h>

int test(char *src)
{
    char buffer[1024];
    strcpy(buffer, src);
    return 1;
}

int main(int argc, char **argv)
{
    test(argv[1]);
    printf("Done..\n");
    return 0;
}
