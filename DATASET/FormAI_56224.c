//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void initializeBoard(int board[][BOARD_SIZE], int* selectedIndexes, int numPairs);
void shuffle(int* array, size_t n);
void printBoard(int board[][BOARD_SIZE], int* selectedIndexes, int numPairs);
int getSelection(int* selectedIndexes, int numPairs);
int checkSelection(int board[][BOARD_SIZE], int* selectedIndexes, int* selection, int numPairs);
int checkWin(int* selectedIndexes, int numPairs);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int numPairs = BOARD_SIZE * BOARD_SIZE / 2;
    int selectedIndexes[numPairs * 2];

    initializeBoard(board, selectedIndexes, numPairs);

    int selection[2];
    int numTries = 0;

    while (!checkWin(selectedIndexes, numPairs)) {
        printf("\n=========\nAttempt %d:\n", numTries + 1);
        printBoard(board, selectedIndexes, numPairs);

        selection[0] = getSelection(selectedIndexes, numPairs);
        selection[1] = getSelection(selectedIndexes, numPairs);

        if (checkSelection(board, selectedIndexes, selection, numPairs)) {
            numTries++;
        }
    }

    printf("You won in %d attempts!\n", numTries);

    return 0;
}

void initializeBoard(int board[][BOARD_SIZE], int* selectedIndexes, int numPairs) {
    int i, j, k;
    int values[numPairs * 2];

    // populate values with pairs of integers
    for (i = 0; i < numPairs; i++) {
        values[2 * i] = i;
        values[2 * i + 1] = i;
    }

    // shuffle values
    shuffle(values, numPairs * 2);

    // initialize board and selectedIndexes
    for (i = 0, k = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++, k++) {
            board[i][j] = values[k];
            selectedIndexes[k] = 0;
        }
    }
}

void shuffle(int* array, size_t n) {
    int i, j, temp;
    srand(time(NULL));

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printBoard(int board[][BOARD_SIZE], int* selectedIndexes, int numPairs) {
    int i, j;

    printf("    ");
    for (j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    printf("\n\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d   ", i);

        for (j = 0; j < BOARD_SIZE; j++) {
            if (selectedIndexes[board[i][j]] || board[i][j] == -1) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

int getSelection(int* selectedIndexes, int numPairs) {
    int selection;
    int validInput = 0;

    while (!validInput) {
        printf("Select a card: ");
        scanf("%d", &selection);

        if (selection < 0 || selection >= numPairs * 2) {
            printf("Invalid selection. Try again.\n");
        } else if (selectedIndexes[selection]) {
            printf("Card already selected. Try again.\n");
        } else {
            validInput = 1;
        }
    }

    selectedIndexes[selection] = 1;

    return selection;
}

int checkSelection(int board[][BOARD_SIZE], int* selectedIndexes, int* selection, int numPairs) {
    if (board[selection[0] / BOARD_SIZE][selection[0] % BOARD_SIZE] == 
        board[selection[1] / BOARD_SIZE][selection[1] % BOARD_SIZE]) {
        printf("Pair found!\n");
        selectedIndexes[selection[0]] = selectedIndexes[selection[1]] = 1;
        return 1;
    } else {
        printf("No pair found.\n");
        printf("Card %d: %d\n", selection[0], board[selection[0] / BOARD_SIZE][selection[0] % BOARD_SIZE]);
        printf("Card %d: %d\n", selection[1], board[selection[1] / BOARD_SIZE][selection[1] % BOARD_SIZE]);
        selectedIndexes[selection[0]] = selectedIndexes[selection[1]] = 0;
        return 0;
    }
}

int checkWin(int* selectedIndexes, int numPairs) {
    int i;
    for (i = 0; i < numPairs * 2; i++) {
        if (!selectedIndexes[i]) {
            return 0;
        }
    }

    return 1;
}