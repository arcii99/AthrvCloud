//FormAI DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Size of the QR code
#define SIZE 10

void generateQR() {
    char qr[SIZE][SIZE]; // Array to hold the QR code
    srand(time(NULL)); // Set random seed

    // Randomly generate dots for the QR code
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(rand()%2 == 0) {
                qr[i][j] = ' ';
            } else {
                qr[i][j] = '#';
            }
        }
    }

    // Display the QR code
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", qr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateQR();
    return 0;
}