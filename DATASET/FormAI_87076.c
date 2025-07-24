//FormAI DATASET v1.0 Category: Chess engine ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 6 // maximum depth to search
#define INFINITY 1000000 // infinity value

int board[8][8] = { // chess board
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

int get_value(int piece){ // function to assign value to pieces
    switch(piece){
        case 1:
        case -1:
            return 100; // value of pawn
        case 2:
        case -2:
            return 320; // value of knight
        case 3:
        case -3:
            return 330; // value of bishop
        case 4:
        case -4:
            return 500; // value of rook
        case 5:
        case -5:
            return 900; // value of queen
        case 6:
        case -6:
            return INFINITY; // value of king
        default:
            return 0;
    }
}

int evaluate(){ // function to evaluate the current board
    int i, j, sum = 0;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            sum += get_value(board[i][j]); // sum of values of pieces on board
        }
    }
    return sum;
}

int minimax(int depth, int alpha, int beta, int player){ // minimax function with alpha beta pruning
    if(depth == 0){ // if maximum depth is reached, evaluate board
        return evaluate();
    }
    int i, j;
    if(player == 1){ // maximizing player
        int max = -INFINITY;
        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(board[i][j] > 0){ // if player 1 piece
                    int temp = board[i][j]; // move piece temporarily
                    board[i][j] = 0;
                    int k, l;
                    for(k=0; k<8; k++){
                        for(l=0; l<8; l++){
                            if(board[k][l] < 0){ // if player 2 piece
                                int temp2 = board[k][l]; // move piece temporarily
                                board[k][l] = temp;
                                int evaluation = minimax(depth-1, alpha, beta, -1) - evaluate();
                                board[k][l] = temp2; // undo move of player 2 piece
                                if(evaluation > max){
                                    max = evaluation;
                                }
                                if(alpha < max){
                                    alpha = max;
                                }
                                if(beta <= alpha){ // beta pruning
                                    return max;
                                }
                            }
                        }
                    }
                    board[i][j] = temp; // undo move of player 1 piece
                }
            }
        }
        return max;
    }else{ // minimizing player
        int min = INFINITY;
        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(board[i][j] < 0){ // if player 2 piece
                    int temp = board[i][j]; // move piece temporarily
                    board[i][j] = 0;
                    int k, l;
                    for(k=0; k<8; k++){
                        for(l=0; l<8; l++){
                            if(board[k][l] > 0){ // if player 1 piece
                                int temp2 = board[k][l]; // move piece temporarily
                                board[k][l] = temp;
                                int evaluation = minimax(depth-1, alpha, beta, 1) + evaluate();
                                board[k][l] = temp2; // undo move of player 1 piece
                                if(evaluation < min){
                                    min = evaluation;
                                }
                                if(beta > min){
                                    beta = min;
                                }
                                if(beta <= alpha){ // alpha pruning
                                    return min;
                                }
                            }
                        }
                    }
                    board[i][j] = temp; // undo move of player 2 piece
                }
            }
        }
        return min;
    }
}

void find_move(){ // function to find the best move
    int i, j;
    int max = -INFINITY;
    int mx, my, nx, ny;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(board[i][j] > 0){ // if player 1 piece
                int temp = board[i][j]; // move piece temporarily
                board[i][j] = 0;
                int k, l;
                for(k=0; k<8; k++){
                    for(l=0; l<8; l++){
                        if(board[k][l] < 0){ // if player 2 piece
                            int temp2 = board[k][l]; // move piece temporarily
                            board[k][l] = temp;
                            int evaluation = minimax(MAX_DEPTH, -INFINITY, INFINITY, -1) - evaluate();
                            board[k][l] = temp2; // undo move of player 2 piece
                            if(evaluation > max){
                                max = evaluation;
                                mx = i;
                                my = j;
                                nx = k;
                                ny = l;
                            }
                        }
                    }
                }
                board[i][j] = temp; // undo move of player 1 piece
            }
        }
    }
    printf("Best move: (%d,%d) to (%d,%d), evaluation: %d\n", mx, my, nx, ny, max); // print best move and evaluation
}

int main(){
    find_move();
    return 0;
}