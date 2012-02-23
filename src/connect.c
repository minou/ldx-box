#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    static int (*sys_connect)(int, const struct sockaddr *, socklen_t) = NULL;
    if (!sys_connect) {
        if (!(*(void **)(&sys_connect) = dlsym(RTLD_NEXT,"connect"))){
            perror("cannot fetch system connect\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "connect:allow", NULL))
        return sys_connect(sockfd, addr, addrlen);
    printf("Forbidden use of connect\n");
    return -1;
}
