#include "ldx-box.h"

static void init(void) __attribute__ ((constructor));

void init(void) {
    ini = iniparser_load((char *) CONFIG);
}
