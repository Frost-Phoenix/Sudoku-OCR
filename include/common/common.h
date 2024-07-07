#if !defined(COMMON_H)
#define COMMON_H


#include <stdint.h>
#include <stdlib.h>


#define BOARD_SIZE 9


typedef struct {
    size_t size;
    uint8_t cells[BOARD_SIZE][BOARD_SIZE];
} board_t;


#endif /* COMMON_H */