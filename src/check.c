#include "ldx-box.h"

int check(const char * path, char ** list, char * delimiter) {
    char * token;
    while ((token = strsep(list, delimiter)) != NULL){
        if (token[0] == '$')
            token = getenv(++token);
        if (strncmp(token, path, strlen(token)) == 0)
            return 1;
    }
    return 0;
}
