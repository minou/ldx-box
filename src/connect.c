#include <stdio.h>
#include "ldx-box.h"

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    static int (*sys_connect)(const char *) = NULL;
    if (!sys_connect) {
        if (!(*(void **)(&sys_connect) = dlsym(RTLD_NEXT,"connect"))){
            perror("cannot fetch system connect\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "connect:allow", NULL)){
//        printf("connect(%i,%i,%i)\n", sockfd, addr, addrlen);
        return sys_connect(sockfd, addr, addrlen);
    }
    printf("Forbidden use of connect.");
    return -1;
}
