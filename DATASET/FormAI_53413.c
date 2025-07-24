//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function prototypes
void print_board(char board[ROWS][COLS]);
void place_ships(char board[ROWS][COLS], int num_ships);
void get_user_input(int *row, int *col);
int check_guess(char board[ROWS][COLS], int row, int col);

int main() {
    char board[ROWS][COLS];
    int num_ships = 5;
    int num_guesses = 0;
    int num_hits = 0;
    srand(time(NULL));

    // initialize board with water
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = '~';
        }
    }

    // place ships randomly
    place_ships(board, num_ships);

    // start game loop
    while (num_hits < num_ships) {
        print_board(board);
        printf("Enter a guess (row col): ");
        int row, col;
        get_user_input(&row, &col);
        if (check_guess(board, row, col)) {
            printf("Hit!\n");
            num_hits++;
            board[row][col] = '*';
        } else {
            printf("Miss.\n");
            board[row][col] = 'o';
        }
        num_guesses++;
    }

    // game over
    print_board(board);
    printf("Congratulations, you sank all the ships with %d guesses!\n", num_guesses);

    return 0;
}

// prints the board
void print_board(char board[ROWS][COLS]) {
    printf("\n   ");
    for (int col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%2d ", row);
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

// randomly places ships on the board
void place_ships(char board[ROWS][COLS], int num_ships) {
    for (int i = 0; i < num_ships; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == 'S') {
            i--;
        } else {
            board[row][col] = 'S';
        }
    }
}

// prompts user for input and sets row and col variables
void get_user_input(int *row, int *col) {
    scanf("%d %d", row, col);
}

// checks if guess is a hit or miss
int check_guess(char board[ROWS][COLS], int row, int col) {
    if (board[row][col] == 'S') {
        return 1;
    } else {
        return 0;
    }
}