//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//initialize the board with starting positions of checkers
char board[8][8] = {
    {'_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'X', '_', 'X', '_', 'X', '_', 'X', '_'},
    {'_', 'X', '_', 'X', '_', 'X', '_', 'X'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'O', '_', 'O', '_', 'O', '_', 'O', '_'},
    {'_', 'O', '_', 'O', '_', 'O', '_', 'O'},
    {'O', '_', 'O', '_', 'O', '_', 'O', '_'}
};

//function to print the current state of the board
void print_board() {
    printf("\n   1 2 3 4 5 6 7 8\n");
    printf("  -----------------\n");
    for(int i=0;i<8;i++) {
        printf("%d| ", i+1);
        for(int j=0;j<8;j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

//function to perform a move
int perform_move(int curr_row, int curr_col, int new_row, int new_col, char player) {
    //check if the move is valid
    if(new_row<0 || new_row >7 || new_col<0 || new_col>7 || player=='_') {
        return 0;
    }
    if(board[new_row][new_col] != '_') {
        return 0;
    }
    if(player=='X' && (new_row>curr_row || abs(curr_col-new_col)>1)) {
        return 0;
    }
    if(player=='O' && (new_row<curr_row || abs(curr_col-new_col)>1)) {
        return 0;
    }
    
    //perform the move and update the board
    board[curr_row][curr_col] = '_';
    board[new_row][new_col] = player;
    
    //if a checker makes it to the other side of the board, crown it as a king
    if(player=='X' && new_row==0) {
        board[new_row][new_col] = 'K';
    }
    if(player=='O' && new_row==7) {
        board[new_row][new_col] = 'K';
    }
    
    return 1;
}

//function to check if a player has won
int check_win(char player) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(board[i][j]==player || board[i][j]=='K') {
                if(i>0 && j>0 && board[i-1][j-1]=='_') {
                    return 0;
                }
                if(i>0 && j<7 && board[i-1][j+1]=='_') {
                    return 0;
                }
                if(i<7 && j>0 && board[i+1][j-1]=='_') {
                    return 0;
                }
                if(i<7 && j<7 && board[i+1][j+1]=='_') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

//main function to run the game
int main() {
    char player = 'X';
    int curr_row, curr_col, new_row, new_col;
    int move_made;
    
    printf("Welcome to Checkers Game!\n");
    printf("X represents Player 1 and O represents Player 2.\n");
    printf("To move a checker, enter its current position and then its new position\n");
    printf("in the format 'row,column'. For example, '1,2' means row=1, column=2.\n");
    
    while(!check_win('X') && !check_win('O')) {
        printf("\nCurrent state of the board:\n");
        print_board();
        
        move_made = 0;
        while(!move_made) {
            printf("\nPlayer %c's turn:\n", player);
            printf("Enter the current position of the checker: ");
            scanf("%d,%d", &curr_row, &curr_col);
            printf("Enter the new position of the checker: ");
            scanf("%d,%d", &new_row, &new_col);
            move_made = perform_move(curr_row-1, curr_col-1, new_row-1, new_col-1, player);
            if(!move_made) {
                printf("Invalid move! Please try again.\n");
            }
        }
        
        if(player=='X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    
    printf("\nCurrent state of the board:\n");
    print_board();
    
    if(check_win('X')) {
        printf("Player 1 (X) wins!\n");
    } else {
        printf("Player 2 (O) wins!\n");
    }
    
    return 0;
}