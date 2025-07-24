//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

int board[BOARD_SIZE];
int flipped[BOARD_SIZE];

void initBoard();
void printBoard();
void flip(int);

int main() {
    int numFlipped = 0, try1, try2;
    initBoard();
    printBoard();

    while (1) {
        printf("Enter first tile to flip (0-15): ");
        scanf("%d", &try1);
        printf("\n");
        while (try1 < 0 || try1 > 15) {
            printf("Invalid input. Enter first tile to flip (0-15): ");
            scanf("%d", &try1);
            printf("\n");
        }
        flip(try1);
        printBoard();

        printf("Enter second tile to flip (0-15): ");
        scanf("%d", &try2);
        printf("\n");
        while (try2 < 0 || try2 > 15) {
            printf("Invalid input. Enter second tile to flip (0-15): ");
            scanf("%d", &try2);
            printf("\n");
        }
        flip(try2);
        printBoard();

        if (board[try1] == board[try2]) {
            printf("Match found!\n");
            numFlipped += 2;
            flipped[try1] = 1;
            flipped[try2] = 1;

            if (numFlipped == BOARD_SIZE) {
                printf("Congratulations! You have won the game!\n");
                return 0;
            }
        } else {
            printf("No match found.\n");
            flip(try1);
            flip(try2);
            printBoard();
        }
    }
}

void initBoard() {
    int values[BOARD_SIZE/2];
    srand(time(NULL));

    // Generate random values for the tiles
    for (int i = 0; i < BOARD_SIZE/2; i++) {
        values[i] = rand()%100 + 1;
    }

    // Shuffle values
    for (int i = 0; i < BOARD_SIZE/2; i++) {
        int randIndex = rand()%(BOARD_SIZE/2);
        int temp = values[i];
        values[i] = values[randIndex];
        values[randIndex] = temp;
    }

    // Place shuffled values onto the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i < BOARD_SIZE/2) {
            board[i] = values[i];
        } else {
            board[i] = values[i - BOARD_SIZE/2];
        }
        flipped[i] = 0;
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (flipped[i] == 1) {
            printf("%d\t", board[i]);
        } else {
            printf("*\t");
        }
        if ((i+1)%4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void flip(int index) {
    if (flipped[index] == 0) {
        flipped[index] = 1;
    } else {
        flipped[index] = 0;
    }
}