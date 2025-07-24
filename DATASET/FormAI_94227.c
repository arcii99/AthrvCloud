//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void printCard(int card[ROWS][COLUMNS], int selectedNumbers[]) {
    printf("\n--------------------------\n");
    printf("|  B  |  I  |  N  |  G  |  O  |\n");
    printf("--------------------------\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == 2 && j == 2) {
                printf("|  F ");
            } else if (card[i][j] == -1) {
                printf("|    ");
            } else {
                printf("| %2d ", card[i][j]);
            }

            if (j == 4) {
                printf("|\n--------------------------\n");
            }
        }
    }

    printf("\nSelected Numbers:");
    for (int i = 0; i < 75; i++) {
        if (selectedNumbers[i] == 1) {
            printf(" %2d", i + 1);
        }
    }
    printf("\n\n");
}

int isBingo(int card[ROWS][COLUMNS]) {

    for (int i = 0; i < ROWS; i++) {
        int marked = 1;
        for (int j = 0; j < COLUMNS; j++) {
            if (card[i][j] != -1) {
                marked = 0;
                break;
            }
        }
        if (marked) {
            return 1;
        }
    }

    for (int j = 0; j < COLUMNS; j++) {
        int marked = 1;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] != -1) {
                marked = 0;
                break;
            }
        }
        if (marked) {
            return 1;
        }
    }

    int marked = 1;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] != -1) {
            marked = 0;
            break;
        }
    }
    if (marked) {
        return 1;
    }

    marked = 1;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][COLUMNS - i - 1] != -1) {
            marked = 0;
            break;
        }
    }
    if (marked) {
        return 1;
    }

    return 0;

}

int main() {

    srand(time(NULL));

    int card[ROWS][COLUMNS];
    int selectedNumbers[75] = {0};

    // Generating random unique numbers for the card
    for (int j = 0; j < COLUMNS; j++) {
        int alreadyAssigned[15] = {0};
        for (int i = 0; i < ROWS; i++) {
            int randomNumber;
            do {
                randomNumber = rand() % 15 + (j * 15) + 1;
            } while (alreadyAssigned[randomNumber - (j * 15) - 1] == 1);
            alreadyAssigned[randomNumber - (j * 15) - 1] = 1;
            card[i][j] = randomNumber;
        }
    }

    // Marking the center box as free space
    card[2][2] = -1;

    // Printing the bingo card
    printCard(card, selectedNumbers);

    // Drawing numbers
    while (1) {
        int drawnNumber;
        do {
            drawnNumber = rand() % 75 + 1;
        } while (selectedNumbers[drawnNumber - 1] == 1);
        selectedNumbers[drawnNumber - 1] = 1;

        printf("\nNumber drawn: %d\n", drawnNumber);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (card[i][j] == drawnNumber) {
                    card[i][j] = -1;
                }
            }
        }

        // Printing the updated card and selected numbers
        printCard(card, selectedNumbers);

        // Checking for bingo
        if (isBingo(card)) {
            printf("\nBINGO!\n");
            break;
        }

        // Asking user to continue or exit
        char choice;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    return 0;

}