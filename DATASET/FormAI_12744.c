//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Function to initialize the checkers board
void init_board(char board[BOARD_SIZE][BOARD_SIZE]){
    // Place player one's pieces
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            if((row + col) % 2 == 0){
                board[row][col] = PLAYER_ONE;
            } else {
                board[row][col] = ' ';
            }
        }
    }
    // Place player two's pieces
    for(int row = BOARD_SIZE - 1; row >= BOARD_SIZE - 3; row--){
        for(int col = 0; col < BOARD_SIZE; col++){
            if((row + col) % 2 == 0){
                board[row][col] = PLAYER_TWO;
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

// Function to print out the checkers board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("  0 1 2 3 4 5 6 7\n");
    for(int row = 0; row < BOARD_SIZE; row++){
        printf("%d ", row);
        for(int col = 0; col < BOARD_SIZE; col++){
            printf("%c|", board[row][col]);
        }
        printf("\n");
    }
}

// Function to move a piece on the board
int move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col, char player){
    // Check if move is valid
    if(board[start_row][start_col] != player) return 0;
    if(board[end_row][end_col] != ' ') return 0;
    if(abs(start_row - end_row) != 1 || abs(start_col - end_col) != 1) return 0;
    if(player == PLAYER_ONE && end_row <= start_row) return 0;
    if(player == PLAYER_TWO && end_row >= start_row) return 0;
    // Make the move
    board[start_row][start_col] = ' ';
    board[end_row][end_col] = player;
    return 1;
}

int main(){
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    char current_player = PLAYER_ONE;
    int game_over = 0;
    int winner = 0;
    while(!game_over){
        print_board(board);
        printf("It is player %c's turn.\n", current_player);
        int start_row, start_col, end_row, end_col;
        printf("Enter the row and column of the piece to move: ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter the row and column of the destination: ");
        scanf("%d %d", &end_row, &end_col);
        if(move(board, start_row, start_col, end_row, end_col, current_player)){
            // switch player if move is valid
            if(current_player == PLAYER_ONE){
                current_player = PLAYER_TWO;
            } else {
                current_player = PLAYER_ONE;
            }
            // Check for winner
            int player_one_pieces = 0, player_two_pieces = 0;
            for(int row = 0; row < BOARD_SIZE; row++){
                for(int col = 0; col < BOARD_SIZE; col++){
                    if(board[row][col] == PLAYER_ONE) player_one_pieces++;
                    if(board[row][col] == PLAYER_TWO) player_two_pieces++;
                }
            }
            if(player_one_pieces == 0){
                winner = 2;
                game_over = 1;
            } else if(player_two_pieces == 0){
                winner = 1;
                game_over = 1;
            }
        }
    }
    print_board(board);
    printf("Player %d has won!\n", winner);
    return 0;
}