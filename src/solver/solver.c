#include "../include/solver/solver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/common/cli.h"


static void _error_wrong_format() {
    print_err("Solver", "wrong file format, expected:");
    printf("... ..4 58.\n");
    printf("... 721 ..3\n");
    printf("4.3 ... ...\n");
    printf("\n");
    printf("21. .67 ..4\n");
    printf(".7. ... 2..\n");
    printf("63. .49 ..1\n");
    printf("\n");
    printf("3.6 ... ...\n");
    printf("... 158 ..6\n");
    printf("... ..6 95.\n");
    printf("11 lines, each 3x3 square separated and empty cells as dots\n");
    exit(EXIT_FAILURE);
}

int _is_digit_valid(uint8_t digit) {
    if (digit > 9) {
        return FALSE;
    }

    return TRUE;
}

void solver_load_board(board_t* board, const char* path) {
    FILE* file;
    char line_buffer[13]; /* 13: 11 character + \n + \0 */
    size_t file_len;

    /* open file */
    file = fopen(path, "r");
    if (file == NULL) {
        print_err("Solver", "can't open '%s'", path);
        exit(EXIT_FAILURE);
    }

    /* go to end of file */
    if (fseek(file, 0, SEEK_END) != 0) {
        print_err("Solver", "fseek failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    /* len = delta between start - end */
    file_len = ftell(file);
    if (file_len != 110) {
        fclose(file);
        _error_wrong_format();
    }

    /* go back to file start */
    fseek(file, 0, SEEK_SET);

    int nb_lines = 0;
    size_t r = 0;
    while (fgets(line_buffer, sizeof(line_buffer), file)) {
        if (line_buffer[0] == '\n') {
            continue;
        }
        size_t c = 0;
        for (size_t i = 0; i < strlen(line_buffer) - 1; i++) {
            if (i == 3 || i == 7) {
                continue;
            }
            uint8_t digit = line_buffer[i] == '.' ? 0 : line_buffer[i] - 48;
            if (!_is_digit_valid(digit)) {
                fclose(file);
                print_err("Solver", "wrong character, expect 1 - 9 and .");
                _error_wrong_format();
            }
            board->cells[r][c] = digit;
            c++;
        }

        nb_lines++;
        r++;
    }

    if (nb_lines != 9) {
        fclose(file);
        _error_wrong_format();
    }

    fclose(file);
}

// int solver_solve(board_t* board) {
//     return 0;
// }

// int solver_save_file(board_t* board, const char* path) {
//     return 0;
// }

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