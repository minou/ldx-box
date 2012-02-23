#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    static int (*sys_bind)(int, const struct sockaddr *, socklen_t) = NULL;
    if (!sys_bind) {
        if (!(*(void **)(&sys_bind) = dlsym(RTLD_NEXT,"bind"))){
            perror("cannot fetch system bind\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "bind:allow", NULL)){
        return sys_bind(sockfd, addr, addrlen);
    }
    printf("Forbidden use of bind\n");
    return -1;
}
