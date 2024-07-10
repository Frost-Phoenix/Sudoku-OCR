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
    size_t start_row = (row / 3) * 3;
    size_t start_col = (col / 3) * 3;

    for (size_t r = start_row; r < start_row + 3; r++) {
        for (size_t c = start_col; c < start_col + 3; c++) {
            if (board->cells[r][c] == nb) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

/******************************************************
 *                 Public functions                   *
 ******************************************************/

int solver_solve(board_t* board) {
    return 0;
}