#include <stdio.h>
#include "ldx-box.h"

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    static int (*sys_accept)(const char *) = NULL;
    if (!sys_accept) {
        if (!(*(void **)(&sys_accept) = dlsym(RTLD_NEXT,"accept"))){
            perror("cannot fetch system accept\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "accept:allow", NULL)){
//        printf("accept(%i,%i,%i)\n", sockfd, addr, addrlen);
        return sys_accept(sockfd, addr, addrlen);
    }
    printf("Forbidden use of accept.");
    return -1;
}
