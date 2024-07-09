#include <criterion/criterion.h>
#include <stdio.h>

#include "../../include/common/types.h"
#include "../../src/solver/solver.c"


board_t board;

void setup(void) {
    board = (board_t){
        .size = 9,
        .cells = { { 0 } },
    };
}

void teardown(void) {
}

Test(solver, col_contains, .init = setup, .fini = teardown) {
    cr_expect(_col_contains(&board, 0, 0) == true);
    cr_expect(_col_contains(&board, 0, 1) == false);
}