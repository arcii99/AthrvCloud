//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

// Function to print the matrix
void printMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to fill the matrix with random values
void fillMatrix(int matrix[][SIZE]) {
    srand(time(0));
    int values[SIZE*SIZE/2];
    for (int i = 0; i < SIZE*SIZE/2; i++) {
        values[i] = i+1;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            int valueIndex = rand() % (SIZE*SIZE/2-j);
            matrix[i][j] = values[valueIndex];
            matrix[i][SIZE-j-1] = values[valueIndex];
            values[valueIndex] = values[SIZE*SIZE/2-j-1];
        }
    }
}

// Function to play the game
void playGame(int matrix[][SIZE]){
    printf("Welcome to the Memory Game!\n");
    int openedCards[SIZE*SIZE/2];
    int numberOfPairs = 0;
    while (numberOfPairs < SIZE*SIZE/2) {
        printf("Enter two cards to open (row1 col1 row2 col2): ");
        int row1, col1, row2, col2;
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
        if (row1 < 1 || row1 > SIZE || col1 < 1 || col1 > SIZE || row2 < 1 || row2 > SIZE || col2 < 1 || col2 > SIZE) {
            printf("Invalid input! Try again.\n");
        }
        else if (matrix[row1-1][col1-1] == 0 || matrix[row2-1][col2-1] == 0) {
            printf("The chosen cards have already been matched! Try again.\n");
        }
        else if (row1 == row2 && col1 == col2) {
            printf("You have chosen the same card twice! Try again.\n");
        }
        else {
            printf("Opening cards...\n");
            printf("Card 1: %d\n", matrix[row1-1][col1-1]);
            printf("Card 2: %d\n", matrix[row2-1][col2-1]);
            if (matrix[row1-1][col1-1] == matrix[row2-1][col2-1]) {
                printf("Congratulations! You have found a pair!\n");
                openedCards[matrix[row1-1][col1-1]-1] = 1;
                matrix[row1-1][col1-1] = 0;
                matrix[row2-1][col2-1] = 0;
                numberOfPairs++;
            }
            else {
                printf("Sorry, try again!\n");
            }
        }
    }
    printf("Congratulations! You have won the game!\n");
}

int main() {
    int matrix[SIZE][SIZE];
    fillMatrix(matrix);
    printMatrix(matrix);
    playGame(matrix);
    return 0;
}