//FormAI DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the board size and win conditions
#define BOARD_SIZE 3
#define WIN_CONDITION 3

// Player and Computer moves are represented by their respective characters
#define PLAYER_MOVE 'X'
#define COMPUTER_MOVE 'O'

// Function to print the current state of the board
void printBoard(char board[][BOARD_SIZE]) {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if(j != BOARD_SIZE-1) printf("|");
        }
        printf("\n");
        if(i != BOARD_SIZE-1) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the game is over, either because a player has won or the board is full
int gameOver(char board[][BOARD_SIZE], char move) {
    // Check for win conditions in rows and columns
    for(int i = 0; i < BOARD_SIZE; i++) {
        int row_matches = 0, col_matches = 0;
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == move) row_matches++;
            if(board[j][i] == move) col_matches++;
        }
        if(row_matches == WIN_CONDITION || col_matches == WIN_CONDITION) return 1;
    }
    
    // Check for win condition in diagonal from top-left to bottom-right
    int diagonal_matches_lr = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[i][i] == move) diagonal_matches_lr++;
    }
    if(diagonal_matches_lr == WIN_CONDITION) return 1;
    
    // Check for win condition in diagonal from bottom-left to top-right
    int diagonal_matches_rl = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board[BOARD_SIZE-i-1][i] == move) diagonal_matches_rl++;
    }
    if(diagonal_matches_rl == WIN_CONDITION) return 1;
    
    // Check if the board is full
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 2;
}

// Function to get the player's move
void getPlayerMove(char board[][BOARD_SIZE], int *x, int *y) {
    printf("Enter your move (row,col): ");
    scanf("%d,%d", x, y);
    
    // Check if move is out of bounds or already taken
    while(*x < 1 || *x > BOARD_SIZE || *y < 1 || *y > BOARD_SIZE || board[*x-1][*y-1] != ' ') {
        printf("Invalid move. Enter your move (row,col): ");
        scanf("%d,%d", x, y);
    }
}

// Function to get the computer's move
void getComputerMove(char board[][BOARD_SIZE], int *x, int *y) {
    // Pick a random move until a valid one is chosen
    do {
        *x = rand() % BOARD_SIZE;
        *y = rand() % BOARD_SIZE;
    } while(board[*x][*y] != ' ');
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player_wins = 0, computer_wins = 0;
    srand(time(NULL)); // Seed random number generator
    
    printf("\n********** Welcome to the Mind-Bending Table Game **********\n\n");
    printf("Instructions:\n");
    printf("1. You are 'X' and the computer is 'O'.\n");
    printf("2. You win by making a row, column, or diagonal of %d 'X's.\n", WIN_CONDITION);
    printf("3. The computer wins by making a row, column, or diagonal of %d 'O's.\n", WIN_CONDITION);
    printf("4. Have fun!\n\n");
    
    // Initialize board to empty spaces
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    while(1) {
        // Player's turn
        int x, y;
        printBoard(board);
        getPlayerMove(board, &x, &y);
        board[x-1][y-1] = PLAYER_MOVE;
        if(gameOver(board, PLAYER_MOVE) == 1) {
            printf("Yay! You won!\n");
            player_wins++;
            break;
        } else if(gameOver(board, PLAYER_MOVE) == 2) {
            printf("The game is a draw.\n");
            break;
        }
        
        // Computer's turn
        printBoard(board);
        printf("The computer is making its move...\n");
        getComputerMove(board, &x, &y);
        board[x][y] = COMPUTER_MOVE;
        if(gameOver(board, COMPUTER_MOVE) == 1) {
            printf("Noooo! You lost!\n");
            computer_wins++;
            break;
        } else if(gameOver(board, COMPUTER_MOVE) == 2) {
            printf("The game is a draw.\n");
            break;
        }
    }
    
    // Print final scores and exit
    printf("Final scores:\n You: %d\n Computer: %d\n", player_wins, computer_wins);
    return 0;
}