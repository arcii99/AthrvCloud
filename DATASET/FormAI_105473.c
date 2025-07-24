//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include<stdio.h>

#define BOARD_SIZE 8

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0; i<3; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if((i+j)%2 == 0){
                board[i][j] = 'B'; // Black checker
            } else {
                board[i][j] = ' ';
            }
        }
    }

    for(int i=3; i<5; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = ' ';
        }
    }

    for(int i=5; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if((i+j)%2 == 0){
                board[i][j] = 'W'; // White checker
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i);
    }
    printf("\n");

    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("%d", i);
        printf("\n");
    }

    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i);
    }
    printf("\n");
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, int new_row, int new_col, char player){
    if(board[new_row][new_col] != ' ') return 0; // cannot move to non-blank space
    if(player == 'B' && new_row < row) return 0; // black can only move downward
    if(player == 'W' && new_row > row) return 0; // white can only move upward
    if(abs(row - new_row) == 1 && abs(col - new_col) == 1) return 1; // normal move
    if(abs(row - new_row) == 2 && abs(col - new_col) == 2){
        int middle_row = (row + new_row) / 2;
        int middle_col = (col + new_col) / 2;
        if(board[middle_row][middle_col] == (player == 'B' ? 'W' : 'B')){
            return 1; // jump move
        }
    }
    return 0;
}

int is_game_over(char board[BOARD_SIZE][BOARD_SIZE]){
    int black_pieces = 0;
    int white_pieces = 0;

    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == 'B') black_pieces++;
            if(board[i][j] == 'W') white_pieces++;
        }
    }

    if(black_pieces == 0){
        printf("White Wins!\n");
        return 1;
    }

    if(white_pieces == 0){
        printf("Black Wins!\n");
        return 1;
    }

    return 0;
}

int main(){
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    char player = 'B';

    while(1){
        int row, col, new_row, new_col;
        printf("%c's Turn\n", player);
        print_board(board);

        printf("Enter current position (row col): ");
        scanf("%d %d", &row, &col);
        printf("Enter new position (row col): ");
        scanf("%d %d", &new_row, &new_col);

        if(is_valid_move(board, row, col, new_row, new_col, player)){
            board[new_row][new_col] = player;
            board[row][col] = ' ';
            int jumped_row = (row + new_row) / 2;
            int jumped_col = (col + new_col) / 2;
            if(abs(row - new_row) == 2){
                board[jumped_row][jumped_col] = ' ';
            }
            if(is_game_over(board)){
                printf("Game Over!\n");
                return 0;
            }
            player = (player == 'B' ? 'W' : 'B'); // switch player
        } else {
            printf("Invalid Move!\n");
        }
    }

    return 0;
}