#include <stdio.h>

#include "../include/common/common.h"
#include "../include/solver/solver.h"


int main(void) {
    board_t board = {
        .size = BOARD_SIZE,
        .cells = { 0 },
    };

    solver_print_board(&board);

    return 0;
}