//FormAI DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 4
#define MAX_COLS 4
#define MAX_MOVES 16

// Structure for holding the game board
struct board {
    int arr[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
};

// Function to initialize the game board
void initialize_board(struct board *game_board) {
    game_board->rows = MAX_ROWS;
    game_board->cols = MAX_COLS;

    // Fill the board with random numbers between 1 and MAX_MOVES/2
    int count = 1;
    for (int i = 0; i < game_board->rows; i++) {
        for (int j = 0; j < game_board->cols; j++) {
            game_board->arr[i][j] = count/2;
            count++;
        }
    }

    // Shuffle the numbers
    srand(time(NULL));
    for (int i = 0; i < game_board->rows; i++) {
        for (int j = 0; j < game_board->cols; j++) {
            int ri = rand() % game_board->rows;
            int rj = rand() % game_board->cols;
            int temp = game_board->arr[i][j];
            game_board->arr[i][j] = game_board->arr[ri][rj];
            game_board->arr[ri][rj] = temp;
        }
    }
}

// Function to display the game board
void display_board(struct board game_board) {
    for (int i = 0; i < game_board.rows; i++) {
        for (int j = 0; j < game_board.cols; j++) {
            printf("%d ", game_board.arr[i][j]);
        }
        printf("\n");
    }
}

// Function to get row and column input from user
void get_input(int *row, int *col) {
    printf("Enter row number (0-%d) and column number (0-%d): ", MAX_ROWS-1, MAX_COLS-1);
    scanf("%d %d", row, col);
}

// Function to update the game board with the player's move
void update_board(struct board *game_board, int row1, int col1, int row2, int col2) {
    int temp = game_board->arr[row1][col1];
    game_board->arr[row1][col1] = game_board->arr[row2][col2];
    game_board->arr[row2][col2] = temp;
}

// Function to check if the game is over
int is_game_over(struct board game_board) {
    int count = 0;
    for (int i = 0; i < game_board.rows; i++) {
        for (int j = 0; j < game_board.cols; j++) {
            if (game_board.arr[i][j] != -1) {
                count++;
            }
        }
    }
    return (count == 0);
}

int main() {
    struct board game_board;
    initialize_board(&game_board);
    
    printf("Welcome to the Memory Game!\n");
    printf("Here is your playing board:\n");
    display_board(game_board);
    
    int row1, col1, row2, col2;
    int moves = 0;
    while (!is_game_over(game_board) && moves < MAX_MOVES) {
        printf("Enter the first card you want to turn over:\n");
        get_input(&row1, &col1);
        while (game_board.arr[row1][col1] == -1) {
            printf("That card has already been matched. Choose another one.\n");
            get_input(&row1, &col1);
        }
        printf("Enter the second card you want to turn over:\n");
        get_input(&row2, &col2);
        while ((game_board.arr[row2][col2] == -1) || (row1 == row2 && col1 == col2)) {
            printf("Invalid card choice. Choose another one.\n");
            get_input(&row2, &col2);
        }
        
        if (game_board.arr[row1][col1] == game_board.arr[row2][col2]) {
            printf("You found a match!\n");
            game_board.arr[row1][col1] = -1;
            game_board.arr[row2][col2] = -1;
        } else {
            printf("Sorry, those cards don't match.\n");
            update_board(&game_board, row1, col1, row2, col2);
        }
        
        printf("Here is your updated playing board:\n");
        display_board(game_board);
        
        moves++;
    }
    
    if (is_game_over(game_board)) {
        printf("Congratulations, you win!\n");
    } else {
        printf("Sorry, you ran out of moves. Better luck next time!\n");
    }

    return 0;
}