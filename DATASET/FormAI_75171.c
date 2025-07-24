//FormAI DATASET v1.0 Category: Chess AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

void display_board(){
    printf("\n  A B C D E F G H\n");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("%d ",i+1);
        for(int j=0;j<BOARD_SIZE;j++){
            switch(board[i][j]){
                case 0: printf(". "); break;
                case 1: printf("P "); break;
                case 2: printf("R "); break;
                case 3: printf("N "); break;
                case 4: printf("B "); break;
                case 5: printf("Q "); break;
                case 6: printf("K "); break;
                case -1: printf("p "); break;
                case -2: printf("r "); break;
                case -3: printf("n "); break;
                case -4: printf("b "); break;
                case -5: printf("q "); break;
                case -6: printf("k "); break;                
            } 
        }
        printf("%d",i+1);
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

void initialize_board(){
    for(int i=2;i<6;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            board[i][j] = 0;
        }
    }
    board[0][0] = 2;
    board[0][1] = 3;
    board[0][2] = 4;
    board[0][3] = 5;
    board[0][4] = 6;
    board[0][5] = 4;
    board[0][6] = 3;
    board[0][7] = 2;
    for(int i=0;i<BOARD_SIZE;i++){
        board[1][i] = 1;
    }
    board[7][0] = -2;
    board[7][1] = -3;
    board[7][2] = -4;
    board[7][3] = -5;
    board[7][4] = -6;
    board[7][5] = -4;
    board[7][6] = -3;
    board[7][7] = -2;
    for(int i=0;i<BOARD_SIZE;i++){
        board[6][i] = -1;
    }
}

int evaluate_board(){
    int score = 0;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            score += board[i][j];
        }
    }
    return score;
}

bool valid_move(int orig_x, int orig_y, int dest_x, int dest_y){
    // Check if destination is in board
    if(dest_x < 0 || dest_x >= BOARD_SIZE || dest_y < 0 || dest_y >= BOARD_SIZE){
        return false;
    }
    // Check if destination is not equal to origin
    if(orig_x == dest_x && orig_y == dest_y){
        return false;
    }
    // Check if move is valid for the piece type
    switch(board[orig_x][orig_y]){
        case 1: // White Pawn
            // Check if destination is in front
            if(dest_x - orig_x == 1 && orig_y == dest_y && board[dest_x][dest_y] == 0){
                return true;
            }
            // Check if destination is diagonal and has enemy piece
            if(dest_x - orig_x == 1 && abs(orig_y - dest_y) == 1 && board[dest_x][dest_y] < 0){
                return true;
            }
            break;
        case -1: // Black Pawn
            // Check if destination is in front
            if(orig_x - dest_x == 1 && orig_y == dest_y && board[dest_x][dest_y] == 0){
                return true;
            }
            // Check if destination is diagonal and has enemy piece
            if(orig_x - dest_x == 1 && abs(orig_y - dest_y) == 1 && board[dest_x][dest_y] > 0){
                return true;
            }
            break;
        //TODO: Implement checks for other pieces
    }
    return false;
}

int minimax(int depth, int alpha, int beta, bool maximizing_player){
    if(depth == 0){
        return evaluate_board();
    }
    if(maximizing_player){
        int max_eval = -99999;
        // Generate possible moves
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j] > 0){ // Check if it's a white piece
                    for(int k=0;k<BOARD_SIZE;k++){
                        for(int l=0;l<BOARD_SIZE;l++){
                            if(valid_move(i,j,k,l)){
                                // Make the move
                                int piece = board[k][l];
                                board[k][l] = board[i][j];
                                board[i][j] = 0;
                                // Recursive call
                                int eval = minimax(depth-1, alpha, beta, false);
                                // Undo the move
                                board[i][j] = board[k][l];
                                board[k][l] = piece;
                                // Update max_eval and alpha
                                if(eval > max_eval){
                                    max_eval = eval;
                                }
                                if(max_eval > alpha){
                                    alpha = max_eval;
                                }
                                if(beta <= alpha){
                                    return max_eval;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max_eval;
    }else{
        int min_eval = 99999;
        // Generate possible moves
        for(int i=0;i<BOARD_SIZE;i++){
            for(int j=0;j<BOARD_SIZE;j++){
                if(board[i][j] < 0){ // Check if it's a black piece
                    for(int k=0;k<BOARD_SIZE;k++){
                        for(int l=0;l<BOARD_SIZE;l++){
                            if(valid_move(i,j,k,l)){
                                // Make the move
                                int piece = board[k][l];
                                board[k][l] = board[i][j];
                                board[i][j] = 0;
                                // Recursive call
                                int eval = minimax(depth-1, alpha, beta, true);
                                // Undo the move
                                board[i][j] = board[k][l];
                                board[k][l] = piece;
                                // Update min_eval and beta
                                if(eval < min_eval){
                                    min_eval = eval;
                                }
                                if(min_eval < beta){
                                    beta = min_eval;
                                }
                                if(beta <= alpha){
                                    return min_eval;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min_eval;
    }
}

int main(){
    initialize_board();
    display_board();
    int depth = 3;
    int best_eval = -99999;
    int best_move[4];
    printf("\nThinking...\n");
    // Generate possible moves
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j] > 0){ // Check if it's a white piece
                for(int k=0;k<BOARD_SIZE;k++){
                    for(int l=0;l<BOARD_SIZE;l++){
                        if(valid_move(i,j,k,l)){
                            // Make the move
                            int piece = board[k][l];
                            board[k][l] = board[i][j];
                            board[i][j] = 0;
                            // Recursive call
                            int eval = minimax(depth-1, -99999, 99999, false);
                            // Undo the move
                            board[i][j] = board[k][l];
                            board[k][l] = piece;
                            // Update best_eval and best_move
                            if(eval > best_eval){
                                best_eval = eval;
                                best_move[0] = i;
                                best_move[1] = j;
                                best_move[2] = k;
                                best_move[3] = l;
                            }
                        }
                    }
                }
            }
        }
    }
    // Make the best move
    printf("\nBest move: %c%d%c%d\n",'A'+best_move[1],best_move[0]+1,'A'+best_move[3],best_move[2]+1);
    int piece = board[best_move[2]][best_move[3]];
    board[best_move[2]][best_move[3]] = board[best_move[0]][best_move[1]];
    board[best_move[0]][best_move[1]] = 0;
    display_board();
    printf("\nPress Enter to exit...\n");
    getchar();
    return 0;
}