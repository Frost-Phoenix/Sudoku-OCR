#if !defined(SOLVER_H)
#define SOLVER_H


#include "../include/common/common.h"


void solver_load_board(board_t* board, const char* path);
int solver_solve(board_t* board);
int solver_save_file(board_t* board, const char* path);

void solver_print_board(board_t* board);


#endif /* SOLVER_H */