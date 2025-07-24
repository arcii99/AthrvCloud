//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
// This program generates a unique QR code

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 25 // Size of the QR code square
#define WHITE "\033[0m" // ASCII code for white
#define BLACK "\033[30m" // ASCII code for black

// Function to randomly generate a binary matrix
void generateMatrix(bool matrix[SIZE][SIZE]) {
    srand(time(NULL)); // Seed the randomizer
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2; // Generate a random number (0 or 1)
        }
    }
}

// Function to print the QR code
void printQRCode(bool matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j]) {
                printf(BLACK "\u25A0" WHITE); // Print a black square
            } else {
                printf(WHITE "\u25A0" WHITE); // Print a white square
            }
        }
        printf("\n"); // Move to the next line
    }
}

int main() {
    bool matrix[SIZE][SIZE];
    generateMatrix(matrix);
    printQRCode(matrix);
    return 0;
}