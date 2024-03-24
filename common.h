#ifndef COMMON_H
#define COMMON_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true    1
#define false   0

#define CHECK_VALID_PTR(ptr) \
    if(ptr == NULL) { \
        printf("Couldn't allocate memory <>\n"); \
        return NULL; \
    }

#endif /* COMMON_H */