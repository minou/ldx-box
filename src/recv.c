#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

ssize_t recv(int sockfd, void *buf, size_t len, int flags){
    static ssize_t (*sys_recv)(int, void *, size_t, int) = NULL;
    if (!sys_recv) {
        if (!(*(void **)(&sys_recv) = dlsym(RTLD_NEXT,"recv"))){
            perror("cannot fetch system recv\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "recv:allow", NULL))
        return sys_recv(sockfd, buf, len, flags);
    printf("Forbidden use of recv\n");
    return -1;
}
