//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

char board[3][3]; //stores 'X' and 'O'
int empty_cells;

/**
 * This function prints the current state of the board
 */
void print_board() {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
            if(j!=2) printf("|");
        }
        printf("\n");
        if(i!=2) printf("------------\n");
    }
}

/**
 * This function checks if the current player has won the game
 */
bool has_won(char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

/**
 * This function checks if the game is over
 */
bool is_game_over() {
    // Check if any player has won
    if (has_won('X')) {
        printf("Congratulations! You have won the game.\n");
        return true;
    }
    if (has_won('O')) {
        printf("Computer has won the game.\n");
        return true;
    }
    // Check if all cells have been filled
    if (empty_cells == 0) {
        printf("The game is a draw.\n");
        return true;
    }
    return false;
}

/**
 * This function gets the user's input and places the mark
 */
void user_turn() {
    int row, col;
    printf("Enter the row and column number (e.g. 1 2): ");
    scanf("%d %d", &row, &col);
    if(board[row-1][col-1] == '.') {
        board[row-1][col-1] = 'X';
        empty_cells--;
    } else {
        printf("Invalid move. Try again.\n");
        user_turn();
    }
}

/**
 * This function uses a simple AI algorithm to make a move
 */
void computer_turn() {
    int row, col;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '.') {
                board[i][j] = 'O';
                if(has_won('O')) {
                    printf("Computer has placed an 'O' in (%d %d).\n", i+1, j+1);
                    empty_cells--;
                    return;
                }
                board[i][j] = '.';
            }
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '.') {
                board[i][j] = 'X';
                if(has_won('X')) {
                    board[i][j] = 'O';
                    printf("Computer has placed an 'O' in (%d %d).\n", i+1, j+1);
                    empty_cells--;
                    return;
                }
                board[i][j] = '.';
            }
        }
    }
    // Place mark randomly
    int i, j;
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while(board[i][j] != '.');
    board[i][j] = 'O';
    printf("Computer has placed an 'O' in (%d %d).\n", i+1, j+1);
    empty_cells--;
}

/**
 * This function is the main game loop
 */
void play_game() {
    empty_cells = 9;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '.';
        }
    }
    print_board();
    while(!is_game_over()) {
        user_turn();
        print_board();
        if(!is_game_over()) {
            computer_turn();
            print_board();
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n\n");
    play_game();
    return 0;
}