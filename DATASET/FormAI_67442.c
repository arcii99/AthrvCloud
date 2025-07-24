//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 15

int board[BOARD_SIZE][BOARD_SIZE];
int mines_found = 0;
int game_won = 0;

// Function to print the board
void print_board() {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Function to initialize the board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to place the mines on the board
void place_mines() {
    srand(time(NULL));
    int num_mines_placed = 0;
    while (num_mines_placed < NUM_MINES) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (board[x][y] != 2) {
            board[x][y] = 2;
            num_mines_placed++;
        }
    }
}

// Function to check if the game is won
void check_game_won() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return;
            }
        }
    }
    game_won = 1;
}

// Function to handle revealing a cell
void handle_cell(int x, int y) {
    if (board[x][y] == 2) {
        printf("You hit a mine! Game over.\n");
        exit(0);
    } else {
        board[x][y] = 1;
        printf("Cell (%d, %d) revealed.\n", x, y);
    }
    mines_found = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                mines_found++;
            }
        }
    }
    printf("%d mines found, %d mines remaining.\n", mines_found, NUM_MINES - mines_found);
    check_game_won();
}

// Main function
int main() {
    init_board();
    place_mines();

    printf("Welcome to the Minesweeper game!\n");
    printf("There are %d mines hidden in a %d x %d board.\n", NUM_MINES, BOARD_SIZE, BOARD_SIZE);
    printf("To reveal a cell, enter its coordinates (x, y).\n");
    printf("Good luck!\n");

    while (!game_won) {
        print_board();
        int x, y;
        printf("Enter coordinates (x, y): ");
        scanf("%d %d", &x, &y);
        handle_cell(x, y);
    }

    printf("Congratulations! You won the game!\n");
    return 0;
}