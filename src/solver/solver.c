#include "../include/solver/solver.h"

#include <stdio.h>

#include "../include/common/cli.h"


int solver_load_board(board_t* board, const char* path) {
    return 0;
}
int solver_solve(board_t* board) {
    return 0;
}

void solver_print_board(board_t* board) {
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    for (size_t i = 0; i < board->size; i++) {
        printf("║");
        for (size_t j = 0; j < board->size; j++) {
            char digit = board->cells[i][j] + 48;
            if (digit == '0') {
                digit = ' ';
            }
            printf(j % 3 == 2 ? " %c ║" : " %c │", digit);
        }
        if (i != 8) {
            printf(i % 3 == 2 ? "\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n"
                : "\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        }
    }
    printf("\n╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}