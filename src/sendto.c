#include <stdio.h>
#include "ldx-box.h"

int sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen){
    static int (*sys_sendto)(const char *) = NULL;
    if (!sys_sendto) {
        if (!(*(void **)(&sys_sendto) = dlsym(RTLD_NEXT,"sendto"))){
            perror("cannot fetch system sendto\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "sendto:allow", NULL)){
//        printf("sendto(%i,%i,%i,%i)\n", sockfd, buf, len, flags, dest_addr, addrlen);
        return sys_sendto(sockfd, buf, len, flags, dest_addr, addrlen);
    }
    printf("Forbidden use of sendto.");
    return -1;
}
