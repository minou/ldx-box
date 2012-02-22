#include <stdio.h>

int main(int argc, char ** argv)
{
    if (argc > 2)
    {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return 1;
    }
    if (remove(argv[1])){
        perror("Error remove");
        return 1;
    }
    printf("Remove file %s\n", argv[1]);
    return 0;
}
