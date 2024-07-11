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

static int _can_assing(board_t* board, size_t row, size_t col, uint8_t nb) {
    int row_contains = _row_contains(board, row, nb);
    int col_contains = _col_contains(board, col, nb);
    int box_contains = _box_contains(board, row, col, nb);
    return !(row_contains || col_contains || box_contains);
}

static int _first_empty_cell(board_t* board, size_t* row, size_t* col) {
    for (size_t r = 0; r < board->size; r++) {
        for (size_t c = 0; c < board->size; c++) {
            if (board->cells[r][c] == 0) {
                *row = r;
                *col = c;
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
    size_t row, col;

    /* no more empty cell, the board is solved */
    if (!_first_empty_cell(board, &row, &col)) {
        return TRUE;
    }

    for (uint8_t nb = 1; nb <= 9; nb++) {
        if (!_can_assing(board, row, col, nb)) {
            continue;
        }

        board->cells[row][col] = nb;

        if (solver_solve(board) == TRUE) {
            return TRUE;
        }

        board->cells[row][col] = 0;
    }


    return FALSE;
}