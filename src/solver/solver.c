#include "../include/solver/solver.h"

#include <stdint.h>
#include <stdlib.h>


/******************************************************
 *                 Private functions                  *
 ******************************************************/

static int _col_contains(board_t* board, size_t col, uint8_t nb) {
    for (size_t r = 0; r < board->size; r++) {
        if (board->cells[r][col] == nb) {
            return TRUE;
        }
    }
    return FALSE;
}

static int _row_contains(board_t* board, size_t row, uint8_t nb) {
    for (size_t c = 0; c < board->size; c++) {
        if (board->cells[row][c] == nb) {
            return TRUE;
        }
    }
    return FALSE;
}

static int _box_contains(board_t* board, size_t row, size_t col, uint8_t nb) {
    // todo
    return TRUE;
}

/******************************************************
 *                 Public functions                   *
 ******************************************************/

int solver_solve(board_t* board) {
    return 0;
}