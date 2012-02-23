#include <stdio.h>
#include "ldx-box.h"

int recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen){
    static int (*sys_recvfrom)(const char *) = NULL;
    if (!sys_recvfrom) {
        if (!(*(void **)(&sys_recvfrom) = dlsym(RTLD_NEXT,"recvfrom"))){
            perror("cannot fetch system recvfrom\n");
            exit(1);
        }
    }

    if (iniparser_getstring(ini, "recvfrom:allow", NULL)){
//        printf("recvfrom(%i,%i,%i,%i)\n", sockfd, buf, len, flags, src_addr, addrlen);
        return sys_recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
    }
    printf("Forbidden use of recvfrom.");
    return -1;
}
