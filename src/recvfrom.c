#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ldx-box.h"

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen){
    static ssize_t (*sys_recvfrom)(int, void *, size_t, int, struct sockaddr *, socklen_t *) = NULL;
    if (!sys_recvfrom) {
        if (!(*(void **)(&sys_recvfrom) = dlsym(RTLD_NEXT,"recvfrom"))){
            perror("cannot fetch system recvfrom\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "recvfrom:allow", NULL))
        return sys_recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
    printf("Forbidden use of recvfrom\n");
    return -1;
}
