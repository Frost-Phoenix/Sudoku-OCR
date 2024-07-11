#if !defined(TYPES_H)
#define TYPES_H


#include <stdint.h>
#include <stdlib.h>

#include "../include/common/constants.h"


typedef struct {
    size_t size;
    uint8_t cells[BOARD_SIZE][BOARD_SIZE];
    uint8_t base_cells[BOARD_SIZE][BOARD_SIZE];
} board_t;


#endif /* TYPES_H */