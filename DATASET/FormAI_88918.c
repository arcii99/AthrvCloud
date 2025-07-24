//FormAI DATASET v1.0 Category: Checkers Game ; Style: imaginative
#include <stdio.h>

// initialize the game board
char board[8][8] = { {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                     {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                     {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
                     {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
                     {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '} };

// function to print the board
void print_board() {
    printf("\n  0 1 2 3 4 5 6 7\n");
    for(int row=0; row<8; row++) {
        printf("%d ", row);
        for(int col=0; col<8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

// function to check if the move is valid or not
int valid_move(int start_row, int start_col, int end_row, int end_col) {
    // check if the end position is empty
    if(board[end_row][end_col] != ' ') {
        return 0;
    }
    
    // check if the move is diagonal
    if(abs(end_row - start_row) != abs(end_col - start_col)) {
        return 0;
    }
    
    // check if the move is forward
    if(board[start_row][start_col] == 'r' && end_row > start_row) {
        return 0;
    } else if(board[start_row][start_col] == 'b' && end_row < start_row) {
        return 0;
    }
    
    // check if the move is not too far
    if(abs(end_row - start_row) > 2) {
        return 0;
    }
    
    // check if the move is capturing an opposing piece
    if(abs(end_row - start_row) == 2) {
        int row_mid = (start_row + end_row) / 2;
        int col_mid = (start_col + end_col) / 2;
        if(board[row_mid][col_mid] == ' ' || board[row_mid][col_mid] == board[start_row][start_col]) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    printf("Welcome to the Checkers Game!\n");
    printf("To make a move, enter the start position and end position separated by spaces.\n");
    printf("For example, to move the piece at position (2,3) to position (3,4), type '2 3 3 4'.\n");
    
    print_board();
    
    int turn = 1; // red goes first
    int game_over = 0;
    
    while(!game_over) {
        int start_row, start_col, end_row, end_col;
        printf("\nPlayer %d's turn.\nEnter your move: ", turn);
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
        
        if(!valid_move(start_row, start_col, end_row, end_col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // move the piece
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = ' ';
        
        // check if the move was a capture
        if(abs(end_row - start_row) == 2) {
            int row_mid = (start_row + end_row) / 2;
            int col_mid = (start_col + end_col) / 2;
            board[row_mid][col_mid] = ' ';
        }
        
        print_board();
        
        // check if the game is over
        int red_count = 0, black_count = 0;
        for(int row=0; row<8; row++) {
            for(int col=0; col<8; col++) {
                if(board[row][col] == 'r') {
                    red_count++;
                } else if(board[row][col] == 'b') {
                    black_count++;
                }
            }
        }
        
        if(red_count == 0) {
            printf("Black wins!\n");
            game_over = 1;
        } else if(black_count == 0) {
            printf("Red wins!\n");
            game_over = 1;
        }
        
        // switch turns
        if(turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
    }
    
    return 0;
}