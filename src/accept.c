#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    static int (*sys_accept)(int, struct sockaddr *, socklen_t *) = NULL;
    if (!sys_accept) {
        if (!(*(void **)(&sys_accept) = dlsym(RTLD_NEXT,"accept"))){
            perror("cannot fetch system accept\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "accept:allow", NULL))
        return sys_accept(sockfd, addr, addrlen);
    printf("Forbidden use of accept\n");
    return -1;
}
