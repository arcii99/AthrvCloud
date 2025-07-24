//FormAI DATASET v1.0 Category: Memory Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(int board[][COLS], int size);
void shuffleBoard(int board[][COLS], int size);
void printBoard(int board[][COLS], int size);
void playGame(int board[][COLS], int size);
int checkIfFinished(int board[][COLS], int size);

int main() {

    int board[ROWS][COLS];
    int size = ROWS * COLS;

    initializeBoard(board, size);
    shuffleBoard(board, size);
    printBoard(board, size);
    playGame(board, size);

    return 0;
}

void initializeBoard(int board[][COLS], int size) {
    srand(time(NULL));
    int nums[size];
    for (int i = 0; i < size; i++) {
        nums[i] = i / 2 + 1;
    }
    for (int i = 0; i < size; i += 2) {
        int index1 = rand() % size;
        int index2;
        do {
            index2 = rand() % size;
        } while (index1 == index2);
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = nums[i * COLS + j];
        }
    }
}

void shuffleBoard(int board[][COLS], int size) {
    int counter = size * 2;
    do {
        int i1 = rand() % ROWS;
        int j1 = rand() % COLS;
        int i2 = rand() % ROWS;
        int j2 = rand() % COLS;

        int temp = board[i1][j1];
        board[i1][j1] = board[i2][j2];
        board[i2][j2] = temp;

        counter--;
    } while (counter > 0);
}

void printBoard(int board[][COLS], int size) {
    printf("Welcome to the Memory Game!\n\n");
    printf("Here is your board:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int board[][COLS], int size) {
    int counter = 0;
    int i1, j1, i2, j2;
    do {
        printf("Enter the row and column of the first card to flip (e.g. row col): ");
        scanf("%d %d", &i1, &j1);
        printf("You flipped: %d\n\n", board[i1][j1]);
        printf("Enter the row and column of the second card to flip (e.g. row col): ");
        scanf("%d %d", &i2, &j2);
        printf("You flipped: %d\n\n", board[i2][j2]);

        if (board[i1][j1] != board[i2][j2]) {
            printf("Sorry, those don't match.\n\n");
            printf("Here is your board:\n\n");
            board[i1][j1] = 0;
            board[i2][j2] = 0;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%d\t", board[i][j]);
                }
                printf("\n");
            }
        } else {
            board[i1][j1] = -1;
            board[i2][j2] = -1;
            printf("Great, those match.\n\n");
            counter += 2;
        }
    } while (counter < size);
    printf("Congratulations, you won!\n");
}

int checkIfFinished(int board[][COLS], int size) {
    int counter = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                counter++;
            }
        }
    }
    return counter == size;
}