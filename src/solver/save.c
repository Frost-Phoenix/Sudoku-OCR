#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/common/macros.h"
#include "../include/solver/solver.h"

#define EXTENTION ".result"


/******************************************************
 *                 Private functions                  *
 ******************************************************/

static const char* _get_path(board_t* board) {
    char* path = malloc(strlen(board->path) + strlen(EXTENTION) + 1);
    if (path == NULL) {
        print_err("Solver", "can't allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(path, board->path);
    strcat(path, EXTENTION);

    return path;
}

/******************************************************
 *                 Public functions                   *
 ******************************************************/

int solver_save_board(board_t* board) {
    const char* path = _get_path(board);

    FILE* file = fopen(path, "w");
    if (file == NULL) {
        print_err("Solver", "can't create file for solved board");
        return FALSE;
    }

    for (size_t r = 0; r < board->size; r++) {
        for (size_t c = 0; c < board->size; c++) {
            char chr = board->cells[r][c] + 48;
            if (chr == '0') {
                chr = '.';
            }
            fprintf(file, "%c", chr);
            if (c == 2 || c == 5) {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
        if (r == 2 || r == 5) {
            fprintf(file, "\n");
        }
    }


    fclose(file);
    free((char*)path);

    return TRUE;
}