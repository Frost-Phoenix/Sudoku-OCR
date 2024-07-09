#include <stdio.h>

#include "../include/common/cli.h"
#include "../include/common/macros.h"
#include "../include/solver/solver.h"


/******************************************************
 *                 Public functions                   *
 ******************************************************/

void solver_print_board(board_t* board) {
    cli_dimmed();
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    for (size_t i = 0; i < board->size; i++) {
        printf("║");
        for (size_t j = 0; j < board->size; j++) {
            char digit = board->cells[i][j] + 48;
            if (digit == '0') {
                digit = ' ';
            }
            cli_reset();
            printf(" %c ", digit);
            cli_dimmed();
            printf(j % 3 == 2 ? "║" : "│");
        }
        if (i != 8) {
            printf(i % 3 == 2 ? "\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n"
                              : "\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        }
    }
    printf("\n╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}