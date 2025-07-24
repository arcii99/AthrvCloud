//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char board[ROWS][COLS];
char solution[ROWS][COLS];
int moves;

void printBoard() {
    printf("\n------------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n------------------------------\n");
    }
}

void generateSolution() {
    int countA = 0; // count of letter A
    int countB = 0; // count of letter B
    int countC = 0; // count of letter C

    srand(time(NULL)); // seed random number generator

    // place letter A
    int rowA = rand() % 4;
    int colA = rand() % 4;
    solution[rowA][colA] = 'A';
    countA++;

    // place letter B
    int rowB, colB;
    do {
        rowB = rand() % 4;
        colB = rand() % 4;
    } while (rowB == rowA && colB == colA);
    solution[rowB][colB] = 'B';
    countB++;

    // place letter C
    int rowC, colC;
    do {
        rowC = rand() % 4;
        colC = rand() % 4;
    } while ((rowC == rowA && colC == colA) || (rowC == rowB && colC == colB));
    solution[rowC][colC] = 'C';
    countC++;

    // place remaining letters randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == rowA && j == colA) {
                continue;
            }
            if (i == rowB && j == colB) {
                continue;
            }
            if (i == rowC && j == colC) {
                continue;
            }
            int letter = rand() % 3; // generate random number from 0 to 2
            if (letter == 0) {
                if (countA < 4) {
                    solution[i][j] = 'A';
                    countA++;
                } else {
                    letter++;
                }
            }
            if (letter == 1) {
                if (countB < 4) {
                    solution[i][j] = 'B';
                    countB++;
                } else {
                    letter++;
                }
            }
            if (letter == 2) {
                if (countC < 4) {
                    solution[i][j] = 'C';
                    countC++;
                } else {
                    letter = 0;
                }
            }
        }
    }
}

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '?';
        }
    }
}

void playMove() {
    int row, col;
    printf("Enter row and column number (seperated by space): ");
    scanf("%d %d", &row, &col);

    // check if input is valid
    if (row < 1 || row > 4 || col < 1 || col > 4) {
        printf("Invalid input, please try again.\n");
        playMove();
        return;
    }
    row--;
    col--;

    // check if cell has already been played
    if (board[row][col] != '?') {
        printf("This cell has already been played, please try again.\n");
        playMove();
        return;
    }

    // update cell with solution letter
    board[row][col] = solution[row][col];
    printBoard();

    // check if game is over
    moves++;
    if (moves >= 16) {
        printf("Congratulations! You have completed the game in %d moves.\n", moves);
        exit(0);
    }

    // ask player to play again
    printf("Do you want to play again? (yes or no): ");
    char answer[3];
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        initializeBoard();
        generateSolution();
        moves = 0;
        playMove();
    } else {
        printf("Thanks for playing!\n");
        exit(0);
    }
}

int main() {
    printf("Welcome to Memory Game!\n\n");
    printf("The goal of the game is to uncover all the letters on the board by matching them in pairs.\n");
    printf("You can make a move by entering the row and column number of the cell you want to uncover.\n");
    printf("If the letters underneath match, they will stay uncovered, otherwise they will be covered again.\n\n");
    printf("Let's start the game!\n");

    initializeBoard();
    generateSolution();
    printBoard();
    playMove();

    return 0;
}