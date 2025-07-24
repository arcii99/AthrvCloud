//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

// Function to print the Bingo Card
void printCard(int card[SIZE][SIZE]) {
    printf("\n");
    printf("   B  I  N  G  O\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (card[r][c] == -1)
                printf("   ");
            else
                printf("%3d", card[r][c]);
        }
        printf("\n");
    }
}

// Function to check if the Bingo Card has a winning pattern
int checkCard(int card[SIZE][SIZE]) {
    // Check rows
    for (int r = 0; r < SIZE; r++) {
        int rowMatch = 1;
        for (int c = 0; c < SIZE; c++) {
            if (card[r][c] != -1) {
                rowMatch = 0;
                break;
            }
        }
        if (rowMatch == 1)
            return 1;
    }
    // Check columns
    for (int c = 0; c < SIZE; c++) {
        int colMatch = 1;
        for (int r = 0; r < SIZE; r++) {
            if (card[r][c] != -1) {
                colMatch = 0;
                break;
            }
        }
        if (colMatch == 1)
            return 1;
    }
    // Check diagonal from top left to bottom right
    int diagMatch = 1;
    for (int i = 0; i < SIZE; i++) {
        if (card[i][i] != -1) {
            diagMatch = 0;
            break;
        }
    }
    if (diagMatch == 1)
        return 1;
    // Check diagonal from bottom left to top right
    diagMatch = 1;
    for (int i = 0; i < SIZE; i++) {
        if (card[i][SIZE-i-1] != -1) {
            diagMatch = 0;
            break;
        }
    }
    if (diagMatch == 1)
        return 1;
    // No winning pattern found
    return 0;
}

// Recursive function to generate the Bingo Card
int generateCard(int card[SIZE][SIZE], int numList[SIZE*SIZE]) {
    // Base case
    if (numList[0] == 0 && checkCard(card) == 0)
        return 0;
    // Recursive case
    int r = rand() % SIZE;
    int c = rand() % SIZE;
    while (card[r][c] != -1) {
        r = rand() % SIZE;
        c = rand() % SIZE;
    }
    card[r][c] = numList[0];
    int newNumList[SIZE*SIZE];
    for (int i = 1; i < SIZE*SIZE; i++)
        newNumList[i-1] = numList[i];
    if (checkCard(card) == 1) {
        printCard(card);
        return 1;
    } else if (generateCard(card, newNumList) == 1) {
        return 1;
    } else {
        card[r][c] = -1;
        return generateCard(card, numList);
    }
}

int main() {
    // Generate list of random numbers
    srand(time(NULL));
    int numList[SIZE*SIZE];
    for (int i = 0; i < SIZE*SIZE; i++)
        numList[i] = i+1;
    for (int i = SIZE*SIZE-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = numList[i];
        numList[i] = numList[j];
        numList[j] = temp;
    }
    // Initialize Bingo Card
    int card[SIZE][SIZE];
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            card[r][c] = -1;
        }
    }
    // Generate Bingo Card
    while (generateCard(card, numList) == 0) {
        // No valid Bingo Card generated, restart
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                card[r][c] = -1;
            }
        }
    }
    return 0;
}