//FormAI DATASET v1.0 Category: Chess engine ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_depth 5

typedef struct piece{
    char piece_type[10];
    int value;
}piece;

typedef struct board{
    piece p[8][8];
    int score;
}board;

int eval(board b){
    //add your evaluation function for cyberpunk style
    return b.score;
}

board minimax(board b, int depth, int alpha, int beta, int maximizing_player){
    if(depth==0){
        b.score = eval(b);
        return b;
    }

    if(maximizing_player){
        int max_score = -10000;
        board max_board;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(strcmp(b.p[i][j].piece_type,"--")==0){
                    continue;
                }
                //generate all moves
                board new_board = b;
                //apply move to new_board
                board child = minimax(new_board, depth-1, alpha, beta, 0);
                if(child.score>max_score){
                    max_score = child.score;
                    max_board = new_board;
                }
                alpha = alpha>max_score ? alpha : max_score;
                if(beta<=alpha){
                    break;
                }
            }
        }
        return max_board;
    }else{
        int min_score = 10000;
        board min_board;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(strcmp(b.p[i][j].piece_type,"--")==0){
                    continue;
                }

                board new_board = b;
                //apply move to new_board
                board child = minimax(new_board, depth-1, alpha, beta, 1);
                if(child.score<min_score){
                    min_score = child.score;
                    min_board = new_board;
                }
                beta = beta<min_score ? beta : min_score;
                if(beta<=alpha){
                    break;
                }
            }
        }
        return min_board;
    }
}

int main(){
    board b;
    //initialize board
    board new_board = minimax(b, max_depth, -10000, 10000, 1);
    //display new_board
    return 0;
}