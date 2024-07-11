#include <stdio.h>

#include "../include/common/cli.h"
#include "../include/common/macros.h"
#include "../include/solver/solver.h"


/******************************************************
 *                 Public functions                   *
 ******************************************************/

void solver_print_board(board_t* board) {
    printf("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
    for (size_t r = 0; r < board->size; r++) {
        printf("║");
        for (size_t c = 0; c < board->size; c++) {
            char digit = board->cells[r][c] + 48;
            if (digit == '0') {
                digit = ' ';
            }
            cli_reset();
            if (board->base_cells[r][c] == 0) {
                cli_set_fg(CLI_GREEN);
            } else {
                cli_set_fg(CLI_BLUE);
            }
            printf(" %c ", digit);
            cli_reset();
            printf(c % 3 == 2 ? "║" : "│");
        }
        if (r != 8) {
            printf(r % 3 == 2 ? "\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n"
                              : "\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        }
    }
    printf("\n╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
}