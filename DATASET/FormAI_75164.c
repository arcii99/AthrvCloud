//FormAI DATASET v1.0 Category: Chess AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define DEPTH 3

int evaluateBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    int score = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            int piece_val = 0;
            if(board[i][j] == 'P') {
                piece_val = 1;
            } else if(board[i][j] == 'N' || board[i][j] == 'B') {
                piece_val = 3;
            } else if(board[i][j] == 'R') {
                piece_val = 5;
            } else if(board[i][j] == 'Q') {
                piece_val = 9;
            } else if(board[i][j] == 'K') {
                piece_val = 0;
            }
            if(board[i][j] > 97) {
                piece_val = -piece_val;
            }
            score += piece_val;
        }
    }
    return score;
}

int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int isMaximizing) {
    if(depth == 0) {
        return evaluateBoard(board);
    }
    
    if(isMaximizing) {
        int maxEval = -1000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] > 97) { //if black piece
                    int temp_board[BOARD_SIZE][BOARD_SIZE];
                    memcpy(temp_board, board, sizeof(temp_board));
                    //simulate move
                    //minimax on that move
                    int eval = minimax(temp_board, depth-1, 0);
                    maxEval = (eval > maxEval) ? eval : maxEval;
                }
            }
        }
        return maxEval;
    } else {
        int minEval = 1000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] <= 90) { //if white piece
                    int temp_board[BOARD_SIZE][BOARD_SIZE];
                    memcpy(temp_board, board, sizeof(temp_board));
                    //simulate move
                    //minimax on that move
                    int eval = minimax(temp_board, depth-1, 1);
                    minEval = (eval < minEval) ? eval : minEval;
                }
            }
        }
        return minEval;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = 
    {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
     {0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0},
     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
     {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
     
    int val = minimax(board, DEPTH, 1);
    printf("The optimal value for white in this game is %d", val);
  
    return 0;
}