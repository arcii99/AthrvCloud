//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function to display the board
void display_board(char board[][COLS]) {
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);

    printf("\t     |     |     \n\n");
}

// Function to check if the game has ended
int game_over(char board[][COLS]) {
    int i, j;
    // Check rows
    for(i=0; i<ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == 'X') return 1;
            else if(board[i][0] == 'O') return 2;
        }
    }
    // Check columns
    for(i=0; i<COLS; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == 'X') return 1;
            else if(board[0][i] == 'O') return 2;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'X') return 1;
        else if(board[0][0] == 'O') return 2;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'X') return 1;
        else if(board[0][2] == 'O') return 2;
    }
    // Check if the board is full
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 3; // Draw
}

// Function to check if a move is valid
int is_valid_move(char board[][COLS], int row, int col) {
    if(row < 0 || row >= ROWS) return 0;
    if(col < 0 || col >= COLS) return 0;
    if(board[row][col] != ' ') return 0;
    return 1;
}

// Function to get the player's move
void get_player_move(char board[][COLS], int *row, int *col) {
    printf("Enter row and column (e.g. 1 2): ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
    while(!is_valid_move(board, *row, *col)) {
        printf("Invalid move! Enter row and column (e.g. 1 2): ");
        scanf("%d %d", row, col);
        (*row)--;
        (*col)--;
    }
}

// Function to get the computer's move
void get_computer_move(char board[][COLS], int *row, int *col) {
    // Check if the computer can win
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(game_over(board) == 2) {
                    *row = i;
                    *col = j;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if the player can win
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(game_over(board) == 1) {
                    *row = i;
                    *col = j;
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Choose a random move
    do {
        *row = rand() % ROWS;
        *col = rand() % COLS;
    } while(!is_valid_move(board, *row, *col));
}

int main() {
    char board[ROWS][COLS];
    int player = 1, winner = 0, row, col;

    // Initialize the board
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = ' ';
        }
    }

    while(winner == 0) {
        // Display the board
        display_board(board);

        // Get the player's move
        if(player == 1) {
            get_player_move(board, &row, &col);
            board[row][col] = 'X';
        }
        // Get the computer's move
        else {
            get_computer_move(board, &row, &col);
            printf("The computer chooses row %d, column %d.\n", row+1, col+1);
            board[row][col] = 'O';
        }
        // Check if the game has ended
        winner = game_over(board);

        // Switch players
        if(player == 1) player = 2;
        else player = 1;
    }

    // Display the final board and winner
    display_board(board);
    if(winner == 1) printf("Player 1 wins!\n");
    else if(winner == 2) printf("Player 2 wins!\n");
    else printf("It's a draw!\n");

    return 0;
}