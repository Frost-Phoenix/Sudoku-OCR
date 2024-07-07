#if !defined(SOLVER_H)
#define SOLVER_H


#include "../include/common/common.h"


int solver_load_board(board_t* board, const char* path);
int solver_solve(board_t* board);

void solver_print_board(board_t* board);


#endif /* SOLVER_H */