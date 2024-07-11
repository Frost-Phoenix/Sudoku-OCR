#include <stdio.h>

#include "../include/common/macros.h"
#include "../include/solver/solver.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_err("Solver", "usage %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    board_t board = {
        .size = BOARD_SIZE,
        .cells = { { 0 } },
        .base_cells = { { 0 } },
    };

    solver_load_board(&board, argv[1]);
    if (!solver_solve(&board)) {
        print_err("Solver", "given board has no solution");
    }
    solver_print_board(&board);

    exit(EXIT_SUCCESS);
}