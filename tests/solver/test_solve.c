#include <criterion/criterion.h>
#include <stdio.h>

#include "../../include/common/types.h"
#include "../../src/solver/loader.c"
#include "../../src/solver/solver.c"


board_t board;

void load_board_0() {
    solver_load_board(&board, "./boards/easy/grid_000");
}

void setup(void) {
    board = (board_t){
        .size = 9,
        .cells = { { 0 } },
    };
}

void teardown(void) {
}

Test(solver, col_contains, .init = setup, .fini = teardown) {
    load_board_0();
    cr_expect(_col_contains(&board, 0, 0) == true);
    cr_expect(_col_contains(&board, 0, 1) == false);
    cr_expect(_col_contains(&board, 6, 1) == true);
}

Test(solver, row_contains, .init = setup, .fini = teardown) {
    load_board_0();
    cr_expect(_row_contains(&board, 0, 0) == true);
    cr_expect(_row_contains(&board, 0, 1) == false);
    cr_expect(_row_contains(&board, 6, 1) == false);
    cr_expect(_row_contains(&board, 7, 9) == true);
}

Test(solver, box_contains, .init = setup, .fini = teardown) {
    load_board_0();
    cr_expect(_box_contains(&board, 0, 0, 0) == true);
    cr_expect(_box_contains(&board, 0, 0, 1) == false);
    cr_expect(_box_contains(&board, 0, 0, 4) == false);
    cr_expect(_box_contains(&board, 0, 0, 7) == true);
    cr_expect(_box_contains(&board, 6, 8, 2) == true);
    cr_expect(_box_contains(&board, 6, 8, 3) == true);
    cr_expect(_box_contains(&board, 6, 8, 5) == false);
    cr_expect(_box_contains(&board, 6, 8, 8) == false);
}