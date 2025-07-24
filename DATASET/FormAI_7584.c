//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global constants to represent the board size and the AI player
#define BOARD_SIZE 3
#define AI_PLAYER 2

// Function to initialize the board with empty spaces
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board in the console
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("-----------\n");
    for(i=0; i<BOARD_SIZE; i++) {
        printf("|");
        for(j=0; j<BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-----------\n");
    }
}

// Function to check if the game board is full
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a player has won the game
int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int i, j, count;

    // Check rows
    for(i=0; i<BOARD_SIZE; i++) {
        count = 0;
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for(j=0; j<BOARD_SIZE; j++) {
        count = 0;
        for(i=0; i<BOARD_SIZE; i++) {
            if(board[i][j] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonal (top left to bottom right)
    count = 0;
    for(i=0; i<BOARD_SIZE; i++) {
        if(board[i][i] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }

    // Check diagonal (bottom left to top right)
    count = 0;
    for(i=0; i<BOARD_SIZE; i++) {
        if(board[i][BOARD_SIZE-1-i] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }

    // Player has not won
    return 0;
}

// Function to get a random move
void get_random_move(int *row, int *col) {
    srand(time(NULL));
    *row = rand() % BOARD_SIZE;
    *col = rand() % BOARD_SIZE;
}

// Function to get the AI player's move
void get_ai_move(char board[BOARD_SIZE][BOARD_SIZE], int *row, int *col) {
    int i, j;
    char temp_board[BOARD_SIZE][BOARD_SIZE];

    // Check if AI can win the game in one move
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                // Try the move
                board[i][j] = AI_PLAYER;
                if(check_winner(board, AI_PLAYER)) {
                    // Winning move found
                    *row = i;
                    *col = j;
                    board[i][j] = ' ';
                    return;
                }
                // Undo the move
                board[i][j] = ' ';
            }
        }
    }

    // Check if the player can win the game in one move and block them
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                // Try the move
                board[i][j] = 1;
                if(check_winner(board, 1)) {
                    // Blocking move found
                    *row = i;
                    *col = j;
                    board[i][j] = ' ';
                    return;
                }
                // Undo the move
                board[i][j] = ' ';
            }
        }
    }

    // No winning or blocking move available, so make a random move
    get_random_move(row, col);
}

int main() {
    // Initialize the game board and other variables
    char board[BOARD_SIZE][BOARD_SIZE];
    char player = 'X';
    int row, col;
    int game_over = 0;

    // Display the welcome message
    printf("Welcome to the Tic Tac Toe game!\n\n");

    // Initialize the game board
    init_board(board);

    // Loop through each player's turn until the game is over
    while(!game_over) {
        // Display the game board
        printf("\n");
        display_board(board);
        printf("\n");

        // Get the current player's move
        if(player == 'X') {
            // Get the human player's move
            printf("It's your turn (X)!\n");
            printf("Enter the row and column separated by a space (e.g. 1 2): ");
            scanf("%d %d", &row, &col);
            while(board[row-1][col-1] != ' ') {
                printf("That space is already taken! Enter a different row and column: ");
                scanf("%d %d", &row, &col);
            }
            board[row-1][col-1] = 'X';
        }
        else {
            // Get the AI player's move
            printf("It's my turn (O)! ");
            get_ai_move(board, &row, &col);
            printf("I choose row %d and column %d.\n", row+1, col+1);
            board[row][col] = 'O';
        }

        // Check if the game is over
        if(check_winner(board, player)) {
            printf("\n");
            display_board(board);
            printf("\n");
            printf("Congratulations, player %c has won the game!\n", player);
            game_over = 1;
        }
        else if(is_board_full(board)) {
            printf("\n");
            display_board(board);
            printf("\n");
            printf("No one has won the game. It's a draw!\n");
            game_over = 1;
        }

        // Switch to the next player
        player = (player == 'X') ? 'O' : 'X';
    }

    // Display the game over message and exit
    printf("\nThanks for playing Tic Tac Toe!\n");
    return 0;
}