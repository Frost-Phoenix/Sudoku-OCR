#include <stdio.h>

#include "../include/common/macros.h"
#include "../include/solver/solver.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_err("Solver", "usage %s <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    board_t board;
    solver_load_board(&board, argv[1]);
    if (!solver_solve(&board)) {
        print_err("Solver", "given board has no solution");
        exit(EXIT_FAILURE);
    }
    solver_print_board(&board);
    solver_save_board(&board);

    exit(EXIT_SUCCESS);
}