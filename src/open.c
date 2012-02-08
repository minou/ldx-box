#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int open(const char *pathname, int flags, ...) {
    static int (*sys_open)(const char *, int) = NULL;
    if (!sys_open) {
        if (!(sys_open =
            (int (*)(const char *, int))dlsym(RTLD_NEXT,"open"))) {
            perror("cannot fetch system open\n");
            exit(1);
        }
    }
    printf("open(%s)\n", pathname);
    return sys_open(pathname, flags);
}
