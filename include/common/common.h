#if !defined(COMMON_H)
#define COMMON_H


#include <stdint.h>
#include <stdlib.h>


#define TRUE  1
#define FALSE 0

#define print_err(NAME, FORMAT, ...)                                 \
    fprintf(stderr, "[\033[31mERROR\033[0m] %s: " FORMAT "\n", NAME, \
            ##__VA_ARGS__)

#define BOARD_SIZE 9


typedef struct {
    size_t size;
    uint8_t cells[BOARD_SIZE][BOARD_SIZE];
} board_t;


#endif /* COMMON_H */