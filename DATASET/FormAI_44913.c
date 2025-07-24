//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // the size of the game grid
#define NUM_MINES 10 // the number of mines in the game
#define MINE 'X' // the character used to represent a mine
#define COVERED '-' // the character used to represent a covered cell
#define HANDLED '*' // the character used to represent a handled cell

// function prototypes
void setup_gameboard(char gameboard[][GRID_SIZE]);
void print_gameboard(char gameboard[][GRID_SIZE]);
void handle_cell(char gameboard[][GRID_SIZE], int row, int col);
int count_adjacent_mines(char gameboard[][GRID_SIZE], int row, int col);
int is_game_over(char gameboard[][GRID_SIZE]);

int main() {
    char gameboard[GRID_SIZE][GRID_SIZE];
    int row, col;

    srand(time(NULL)); // seed the random number generator

    setup_gameboard(gameboard); // place mines on the gameboard
    print_gameboard(gameboard); // print the initial state of the gameboard

    while (!is_game_over(gameboard)) {
        printf("Enter the row and column of the cell to handle: ");
        scanf("%d %d", &row, &col);
        handle_cell(gameboard, row, col);
        print_gameboard(gameboard);
    }

    printf("Game over.\n");

    return 0;
}

/* Sets up the gameboard by randomly placing mines on it */
void setup_gameboard(char gameboard[][GRID_SIZE]) {
    int row, col, num_mines_placed = 0;

    // initialize gameboard to all 'covered' cells
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            gameboard[row][col] = COVERED;
        }
    }

    // place mines on gameboard at random locations
    while (num_mines_placed < NUM_MINES) {
        int rand_row = rand() % GRID_SIZE;
        int rand_col = rand() % GRID_SIZE;

        if (gameboard[rand_row][rand_col] != MINE) {
            gameboard[rand_row][rand_col] = MINE;
            num_mines_placed++;
        }
    }
}

/* Prints the current state of the gameboard */
void print_gameboard(char gameboard[][GRID_SIZE]) {
    int row, col;

    printf("   ");
    for (col = 0; col < GRID_SIZE; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");

    for (row = 0; row < GRID_SIZE; row++) {
        printf("%2d ", row + 1);
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%c ", gameboard[row][col]);
        }
        printf("\n");
    }
}

/* Handles the selected cell on the gameboard */
void handle_cell(char gameboard[][GRID_SIZE], int row, int col) {
    if (gameboard[row][col] == MINE) {
        gameboard[row][col] = HANDLED;
    } else {
        int adjacent_mines = count_adjacent_mines(gameboard, row, col);
        gameboard[row][col] = '0' + adjacent_mines;
    }
}

/* Counts the number of adjacent mines to the selected cell */
int count_adjacent_mines(char gameboard[][GRID_SIZE], int row, int col) {
    int count = 0, i, j;

    // check the 8 adjacent cells
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE && gameboard[i][j] == MINE) {
                count++;
            }
        }
    }

    return count;
}

/* Checks if the game is over */
int is_game_over(char gameboard[][GRID_SIZE]) {
    int row, col;

    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (gameboard[row][col] == COVERED) {
                return 0; // there are still covered cells, game is not over
            }
        }
    }

    return 1; // all cells are uncovered, game is over
}