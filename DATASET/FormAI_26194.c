//FormAI DATASET v1.0 Category: Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define macros for game parameters */
#define ROWS 10
#define COLS 10
#define MAX_MOVES 20
#define NUM_MINES 10

/* Define global variables */
int mines_left = NUM_MINES;
int moves_made = 0;
char board[ROWS][COLS];
int visited[ROWS][COLS];
int mine_positions[2][NUM_MINES];

/* Function to generate random mine positions */
void generate_mine_positions() {
    int i, row, col;
    srand(time(NULL));
    for (i = 0; i < NUM_MINES; i++) {
        row = rand() % ROWS;
        col = rand() % COLS;
        if (board[row][col] == 'M') {
            i--;
        } else {
            board[row][col] = 'M';
            mine_positions[0][i] = row;
            mine_positions[1][i] = col;
        }
    }
}

/* Function to show board to player */
void show_board() {
    int row, col;
    printf("   ");
    for (col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for (row = 0; row < ROWS; row++) {
        printf("%d  ", row);
        for (col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

/* Function to check if player has won */
int check_win() {
    int i;
    int win = 1;
    for (i = 0; i < NUM_MINES; i++) {
        if (visited[mine_positions[0][i]][mine_positions[1][i]] == 0) {
            win = 0;
            break;
        }
    }
    return win;
}

/* Recursive function to reveal cells */
void reveal_cells(int row, int col) {
    int i, j, count = 0;
    visited[row][col] = 1;
    if (board[row][col] == 'M') {
        printf("Sorry, you have stepped on a mine. Game over.\n");
        exit(0);
    }
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (row + i >= 0 && row + i < ROWS && col + j >= 0 && col + j < COLS) {
                if (board[row + i][col + j] == 'M') {
                    count++;
                }
            }
        }
    }
    board[row][col] = count + '0';
    if (board[row][col] == '0') {
        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if (row + i >= 0 && row + i < ROWS && col + j >= 0 && col + j < COLS) {
                    if (visited[row + i][col + j] == 0) {
                        reveal_cells(row + i, col + j);
                    }
                }
            }
        }
    }
}

/* Function to play the game */
void play_game() {
    int row, col;
    char input[10];
    while (moves_made < MAX_MOVES && mines_left > 0) {
        printf("Enter row and column to reveal: ");
        fgets(input, 10, stdin);
        row = atoi(&input[0]);
        col = atoi(&input[2]);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (visited[row][col] == 0) {
                reveal_cells(row, col);
                moves_made++;
                printf("Moves made: %d\n", moves_made);
                printf("Mines left: %d\n", mines_left);
                show_board();
                if (check_win() == 1) {
                    printf("Congratulations, you have won the game!\n");
                    exit(0);
                }
            } else {
                printf("The cell has already been visited. Please choose another cell.\n");
            }
        } else {
            printf("Invalid row or column. Please enter valid inputs.\n");
        }
    }
    if (mines_left == 0) {
        printf("Congratulations, you have found all the mines! You win!\n");
    } else {
        printf("Sorry, you have used all your moves. Game over!\n");
    }
}

/* Main function to run the game */
int main() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
            visited[i][j] = 0;
        }
    }
    generate_mine_positions();
    show_board();
    play_game();
    return 0;
}