#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen) {
    static ssize_t (*sys_sendto)(int, const void *, size_t, int, const struct sockaddr *, socklen_t) = NULL;
    if (!sys_sendto) {
        if (!(*(void **)(&sys_sendto) = dlsym(RTLD_NEXT,"sendto"))){
            perror("cannot fetch system sendto\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "sendto:allow", NULL))
        return sys_sendto(sockfd, buf, len, flags, dest_addr, addrlen);
    printf("Forbidden use of sendto\n");
    return -1;
}
