//FormAI DATASET v1.0 Category: Chess AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 99999
#define PEMPT 0 //Empty square
#define PPAWN 1
#define PBISHOP 2
#define PKNIGHT 3
#define PCASTLE 4
#define PQUEEN 5
#define PKING 6

#define WPAWN 11
#define WBISHOP 12
#define WKNIGHT 13
#define WCASTLE 14
#define WQUEEN 15
#define WKING 16

#define MAX_DEPTH 3

typedef struct {
    int type; //Type of piece
    int color; //0 for black, 1 for white
} piece;

int evaluation(piece board[8][8]){
    int score = 0;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            switch(board[i][j].type){
                case PPAWN:
                    score += board[i][j].color ? 10 : -10;
                    break;
                case PBISHOP:
                    score += board[i][j].color ? 30 : -30;
                    break;
                case PKNIGHT:
                    score += board[i][j].color ? 30 : -30;
                    break;
                case PCASTLE:
                    score += board[i][j].color ? 50 : -50;
                    break;
                case PQUEEN:
                    score += board[i][j].color ? 90 : -90;
                    break;
                case PKING:
                    score += board[i][j].color ? 900 : -900;
                    break;
                default: //Empty square
                    break;
            }
        }
    }

    return score;
}

int minmax(piece board[8][8], int depth, int isMaximizingPlayer, int alpha, int beta){
    if(depth == MAX_DEPTH){
        return evaluation(board);
    }

    //Assuming the maximizer is white
    if(isMaximizingPlayer){
        int bestScore = -INF;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j].color == 1){ //White piece
                    switch(board[i][j].type){
                        case WPAWN:
                            //TODO
                            break;
                        case WBISHOP:
                            //TODO
                            break;
                        case WKNIGHT:
                            //TODO
                            break;
                        case WCASTLE:
                            //TODO
                            break;
                        case WQUEEN:
                            //TODO
                            break;
                        case WKING:
                            //TODO
                            break;
                        default: //Empty square or black piece
                            break;
                    }
                }
            }
        }
        return bestScore;
    }
    else{ //Minimizing player (black)
        int bestScore = INF;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j].color == 0){ //Black piece
                    switch(board[i][j].type){
                        case PPAWN:
                            //TODO
                            break;
                        case PBISHOP:
                            //TODO
                            break;
                        case PKNIGHT:
                            //TODO
                            break;
                        case PCASTLE:
                            //TODO
                            break;
                        case PQUEEN:
                            //TODO
                            break;
                        case PKING:
                            //TODO
                            break;
                        default: //Empty square or white piece
                            break;
                    }
                }
            }
        }
        return bestScore;
    }
}

int main(){
    piece board[8][8] = {{ {WCASTLE,1}, {WKNIGHT,1}, {WBISHOP,1}, {WQUEEN,1},
                          {WKING,1}, {WBISHOP,1}, {WKNIGHT,1}, {WCASTLE,1} },
                         { {WPAWN,1}, {WPAWN,1}, {WPAWN,1}, {WPAWN,1},
                          {WPAWN,1}, {WPAWN,1}, {WPAWN,1}, {WPAWN,1} },
                         { {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0},
                          {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0} },
                         { {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0},
                          {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0} },
                         { {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0},
                          {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0} },
                         { {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0},
                          {PEMPT,0}, {PEMPT,0}, {PEMPT,0}, {PEMPT,0} },
                         { {PPAWN,0}, {PPAWN,0}, {PPAWN,0}, {PPAWN,0},
                          {PPAWN,0}, {PPAWN,0}, {PPAWN,0}, {PPAWN,0} },
                         { {PCASTLE,0}, {PKNIGHT,0}, {PBISHOP,0}, {PQUEEN,0},
                          {PKING,0}, {PBISHOP,0}, {PKNIGHT,0}, {PCASTLE,0} }};
    int bestScore = -INF;
    int alpha = -INF;
    int beta = INF;
    int bestMove[4] = {0,0,0,0}; //Format is {start row, start col, end row, end col}

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j].color == 1){ //White piece
                switch(board[i][j].type){
                    case WPAWN:
                        //TODO
                        break;
                    case WBISHOP:
                        //TODO
                        break;
                    case WKNIGHT:
                        //TODO
                        break;
                    case WCASTLE:
                        //TODO
                        break;
                    case WQUEEN:
                        //TODO
                        break;
                    case WKING:
                        //TODO
                        break;
                    default: //Empty square or black piece
                        break;
                }
            }
        }
    }

    printf("Best move: %d(%d,%d) to %d(%d,%d)\n", board[bestMove[0]][bestMove[1]].type, bestMove[0], bestMove[1], board[bestMove[2]][bestMove[3]].type, bestMove[2], bestMove[3]);

    return 0;
}