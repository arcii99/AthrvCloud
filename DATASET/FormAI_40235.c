//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 25

int board[ROWS][COLUMNS];
int score;

// function declarations
void initBoard();
void printBoard();
void updateBoard(int, int);
void movePacman();

int main() {
    int row, col;

    initBoard(); // initialize the board
    printBoard(); // print the board

    movePacman();

    printf("Game over. Your score is %d.\n", score);

    return 0;
}

// function to initialize the board
void initBoard() {
    srand(time(NULL)); // seed random number generator

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int r = rand() % 10;
            board[i][j] = (r < 8 ? 0 : 1); // 80% probability of being 0, 20% probability of being 1 (representing dots)
        }
    }

    board[ROWS / 2][COLUMNS / 2] = -1; // set the starting position for Pac-Man
}

// function to print the board
void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("O ");
                    break;
                case -1:
                    printf("P ");
                    break;
            }
        }

        printf("\n");
    }

    printf("Score: %d\n", score);
}

// function to update the board after Pac-Man moves
void updateBoard(int row, int col) {
    if (board[row][col] == 1) { // Pac-Man ate a dot
        score++;
    }

    board[row][col] = -1; // update Pac-Man's position

    printBoard(); // print the updated board
}

// function to move Pac-Man
void movePacman() {
    int row = ROWS / 2;
    int col = COLUMNS / 2;

    while (1) {
        char input = getchar();

        // move Pac-Man
        switch (input) {
            case 'w':
                if (row > 0 && board[row - 1][col] != 9) {
                    row--;
                }

                break;
            case 'a':
                if (col > 0 && board[row][col - 1] != 9) {
                    col--;
                }

                break;
            case 's':
                if (row < ROWS - 1 && board[row + 1][col] != 9) {
                    row++;
                }

                break;
            case 'd':
                if (col < COLUMNS - 1 && board[row][col + 1] != 9) {
                    col++;
                }

                break;
            default:
                continue;
        }

        updateBoard(row, col);

        // check if game is over
        int dots = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (board[i][j] == 1) {
                    dots++;
                }
            }
        }

        if (dots == 0) {
            break;
        }
    }
}