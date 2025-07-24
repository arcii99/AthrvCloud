//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

// Function to initialize the game board with random values
void initialize_board(int board[][BOARD_SIZE]) {
    srand(time(0));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 3 + 1;
        }
    }
}

// Function to print the game board
void print_board(int board[][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A'+i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to handle player moves
void player_move(int board[][BOARD_SIZE], int *score) {
    int row, col;
    do {
        printf("Enter row and col (ex: A1): ");
        char input[4];
        scanf("%s", input);
        row = input[0] - 'A';
        col = input[1] - '1';
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE);
    
    int value = board[row][col];
    *score += value;
    board[row][col] = 0;
    
    // Move remaining numbers down
    for (int i = BOARD_SIZE-1; i >= 0; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                int row_above = i - 1;
                while (row_above >= 0) {
                    if (board[row_above][j] != 0) {
                        board[i][j] = board[row_above][j];
                        board[row_above][j] = 0;
                        break;
                    }
                    row_above--;
                }
            }
        }
    }
}

// Function to check if the game is over
int check_game_over(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                if (i == 0 || (i > 0 && board[i-1][j] == 0)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Main function to run the game
int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int score = 0;
    initialize_board(board);
    
    printf("Welcome to the game!\n");
    print_board(board);
    
    while (!check_game_over(board)) {
        printf("Your current score: %d\n", score);
        player_move(board, &score);
        print_board(board);
    }
    
    printf("Game over! Your final score: %d\n", score);
    return 0;
}