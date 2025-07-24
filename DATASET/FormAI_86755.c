//FormAI DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

int board[BOARD_SIZE][BOARD_SIZE];
int checkBoard[BOARD_SIZE][BOARD_SIZE];
int pairCount = 0;

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    printf("   ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n");

    printf("  +");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("- ");
    }
    printf("+\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", checkBoard[i][j]);
        }
        printf("|\n");
    }

    printf("  +");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("- ");
    }
    printf("+\n");
}

void printChar(char c, int times) {
    for (int i = 0; i < times; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void initializeCheckBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            checkBoard[i][j] = '?';
        }
    }
}

void addPair(int number) {
    int count = 0;
    while (count < 2) {
        int i = rand() % BOARD_SIZE;
        int j = rand() % BOARD_SIZE;
        if (board[i][j] == 0) {
            board[i][j] = number;
            count++;
        }
    }
}

void generateBoard() {
    pairCount = 0;
    int i = 1;
    while (i <= MAX_PAIRS) {
        addPair(i);
        i++;
    }
}

void printIntro() {
    printChar('*', 30);
    printf("Welcome to C Memory Game!\n");
    printChar('*', 30);
    printf("\n\n");

    printf("Instructions:\n");
    printf("- There are %d pairs of numbers hidden in the board.\n", MAX_PAIRS);
    printf("- The player needs to find all pairs in as few tries as possible.\n");
    printf("- The board has the following format:\n\n");

    printBoard();
}

int getNumber() {
    int number = -1;
    printf("Enter a number (0 to quit): ");
    scanf("%d", &number);
    return number;
}

int getRowIndex() {
    int index = -1;
    printf("Enter row index: ");
    scanf("%d", &index);
    return index;
}

int getColumnIndex() {
    int index = -1;
    printf("Enter column index: ");
    scanf("%d", &index);
    return index;
}

void checkPair(int number, int i1, int j1, int i2, int j2) {
    if (number != board[i1][j1] || number != board[i2][j2]) {
        printf("Sorry, those numbers are not a pair.\n");
        printf("Press enter to continue...");
        getchar();
        getchar();
        checkBoard[i1][j1] = '?';
        checkBoard[i2][j2] = '?';
    } else {
        printf("Congratulations! You found a pair!\n");
        printf("Press enter to continue...");
        getchar();
        getchar();
        checkBoard[i1][j1] = number;
        checkBoard[i2][j2] = number;
        pairCount++;
    }
}

int isGameOver() {
    return pairCount == MAX_PAIRS;
}

int main() {
    srand(time(NULL));
    initializeBoard();
    initializeCheckBoard();
    generateBoard();
    printIntro();
    int gameOver = 0;
    int tries = 0;

    while (!gameOver) {
        printf("\n\n");
        printBoard();
        int number = getNumber();
        if (number == 0) {
            break;
        }

        int i1 = getRowIndex();
        int j1 = getColumnIndex();
        checkBoard[i1][j1] = board[i1][j1];

        int i2 = getRowIndex();
        int j2 = getColumnIndex();
        checkBoard[i2][j2] = board[i2][j2];

        checkPair(number, i1, j1, i2, j2);
        tries++;

        gameOver = isGameOver();
    }

    if (gameOver) {
        printf("\n\nCongratulations! You won with %d tries!\n", tries);
    } else {
        printf("\n\nGoodbye!\n");
    }

    return 0;
}