#if !defined(MACROS_H)
#define MACROS_H


#include <stdlib.h>


#define print_err(NAME, FORMAT, ...)                                 \
    fprintf(stderr, "[\033[31mERROR\033[0m] %s: " FORMAT "\n", NAME, \
            ##__VA_ARGS__)


#endif /* MACROS_H */