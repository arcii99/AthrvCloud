//FormAI DATASET v1.0 Category: Chess engine ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

#define MAX_DEPTH 5

int evaluation_board(char board[8][8], int side);
int minimax(char board[8][8], int depth, int alpha, int beta, int max_player);
int get_best_move(char board[8][8], int side);

int evaluation_board(char board[8][8], int side){
    int score = 0;
  
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 'P') score += 10;
            if(board[i][j] == 'N') score += 30;
            if(board[i][j] == 'B') score += 30;
            if(board[i][j] == 'R') score += 50;
            if(board[i][j] == 'Q') score += 90;
            if(board[i][j] == 'K') score += 900;
            if(board[i][j] == 'p') score -= 10;
            if(board[i][j] == 'n') score -= 30;
            if(board[i][j] == 'b') score -= 30;
            if(board[i][j] == 'r') score -= 50;
            if(board[i][j] == 'q') score -= 90;
            if(board[i][j] == 'k') score -= 900;
        }
    }
    
    return side == WHITE ? score : -score;
}

int minimax(char board[8][8], int depth, int alpha, int beta, int max_player){
    if(depth == 0) return evaluation_board(board, WHITE);

    int best_move = max_player ? -100000 : 100000;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((board[i][j] == 'K' && max_player == 0) || (board[i][j] == 'k' && max_player == 1))
                return max_player == 0 ? -100000 : 100000;

            if((board[i][j] == 'p' && max_player == 1) || (board[i][j] == 'P' && max_player == 0)){

                // Check for possible moves
                if((max_player == WHITE && board[i-1][j] == ' ') || (max_player == BLACK && board[i+1][j] == ' ')) {
                    char temp_board[8][8];
                    memcpy(temp_board, board, sizeof(temp_board));
                    temp_board[i][j] = ' ';
                    temp_board[max_player == WHITE ? i-1 : i+1][j] = max_player == WHITE ? 'P' : 'p';

                    int move_value = minimax(temp_board, depth-1, alpha, beta, !max_player);
                    if(max_player){
                        if(move_value >= beta) return beta;
                        if(move_value > alpha) alpha = move_value;
                        if(move_value > best_move) best_move = move_value;
                    }
                    else{
                        if(move_value <= alpha) return alpha;
                        if(move_value < beta) beta = move_value;
                        if(move_value < best_move) best_move = move_value;
                    }
                }

                // Check for possible captures
                if((max_player == WHITE && board[i-1][j-1] >= 'a' && board[i-1][j-1] <= 'z') ||
                   (max_player == WHITE && board[i-1][j+1] >= 'a' && board[i-1][j+1] <= 'z') ||
                   (max_player == BLACK && board[i+1][j-1] >= 'A' && board[i+1][j-1] <= 'Z') ||
                   (max_player == BLACK && board[i+1][j+1] >= 'A' && board[i+1][j+1] <= 'Z')){
                    char temp_board[8][8];
                    memcpy(temp_board, board, sizeof(temp_board));
                    temp_board[i][j] = ' ';
                    temp_board[max_player == WHITE ? i-1 : i+1][j-1] = ' ';
                    temp_board[max_player == WHITE ? i-1 : i+1][j+1] = ' ';
                    temp_board[max_player == WHITE ? i-1 : i+1][j-1] = max_player == WHITE ? 'P' : 'p';

                    int move_value = minimax(temp_board, depth-1, alpha, beta, !max_player);
                    if(max_player){
                        if(move_value >= beta) return beta;
                        if(move_value > alpha) alpha = move_value;
                        if(move_value > best_move) best_move = move_value;
                    }
                    else{
                        if(move_value <= alpha) return alpha;
                        if(move_value < beta) beta = move_value;
                        if(move_value < best_move) best_move = move_value;
                    }
                }
            }
        }
    }

    return best_move;
}

int get_best_move(char board[8][8], int side){
    int best_value = side == WHITE ? -100000 : 100000;
    int best_i, best_j;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((board[i][j] == 'P' && side == WHITE) || (board[i][j] == 'p' && side == BLACK)){

                // Check for possible moves
                if((side == WHITE && board[i-1][j] == ' ') || (side == BLACK && board[i+1][j] == ' ')) {
                    char temp_board[8][8];
                    memcpy(temp_board, board, sizeof(temp_board));
                    temp_board[i][j] = ' ';
                    temp_board[side == WHITE ? i-1 : i+1][j] = side == WHITE ? 'P' : 'p';

                    int move_value = minimax(temp_board, MAX_DEPTH, -100000, 100000, side == WHITE ? 1 : 0);
                    if(side == WHITE && move_value > best_value){
                        best_value = move_value;
                        best_i = i-1;
                        best_j = j;
                    }
                    else if(side == BLACK && move_value < best_value){
                        best_value = move_value;
                        best_i = i+1;
                        best_j = j;
                    }
                }

                // Check for possible captures
                if((side == WHITE && board[i-1][j-1] >= 'a' && board[i-1][j-1] <= 'z') ||
                   (side == WHITE && board[i-1][j+1] >= 'a' && board[i-1][j+1] <= 'z') ||
                   (side == BLACK && board[i+1][j-1] >= 'A' && board[i+1][j-1] <= 'Z') ||
                   (side == BLACK && board[i+1][j+1] >= 'A' && board[i+1][j+1] <= 'Z')){
                    char temp_board[8][8];
                    memcpy(temp_board, board, sizeof(temp_board));
                    temp_board[i][j] = ' ';
                    temp_board[side == WHITE ? i-1 : i+1][j-1] = ' ';
                    temp_board[side == WHITE ? i-1 : i+1][j+1] = ' ';
                    temp_board[side == WHITE ? i-1 : i+1][j-1] = side == WHITE ? 'P' : 'p';

                    int move_value = minimax(temp_board, MAX_DEPTH, -100000, 100000, side == WHITE ? 1 : 0);
                    if(side == WHITE && move_value > best_value){
                        best_value = move_value;
                        best_i = i-1;
                        best_j = j-1;
                    }
                    else if(side == BLACK && move_value < best_value){
                        best_value = move_value;
                        best_i = i+1;
                        best_j = j+1;
                    }
                }
            }
        }
    }

    printf("Best move: %d,%d\n", best_i, best_j);
    return 0;
}

int main(){
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    get_best_move(board, WHITE);
    return 0;
}