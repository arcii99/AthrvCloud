//FormAI DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define size of QR code
#define SIZE 25

// Define colors
#define WHITE 0
#define BLACK 1

int qrCode[SIZE][SIZE];

// Define a function to set a specific module to black
void setModule(int x, int y) {
    qrCode[x][y] = BLACK;
}

// Define a function to set a specific module to white
void unsetModule(int x, int y) {
    qrCode[x][y] = WHITE;
}

// Define a function to print out the QR code
void printQR() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (qrCode[i][j] == BLACK) {
                printf("\u2588"); // Unicode block element to represent black color
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set all modules to white initially
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            unsetModule(i, j);
        }
    }

    // Generate random black modules
    for (int i = 0; i < SIZE/2; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        setModule(x, y);
    }

    // Print out the QR code
    printQR();

    return 0;
}