//FormAI DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the QR code
#define SIZE 10

// Define the color of the QR code
#define COLOR "purple"

// Define the format of the QR code
#define FORMAT "png"

int main() {
    // Initialize the QR code image
    char qr_code[SIZE][SIZE];

    // Fill the image with random characters
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            qr_code[i][j] = rand() % 2 == 0 ? '1' : '0';
        }
    }

    // Generate the QR code text
    char qr_text[SIZE * SIZE];
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            qr_text[k++] = qr_code[i][j];
        }
    }
    qr_text[k] = '\0';

    // Output the QR code
    printf("QR code generated!\n");
    printf("Color: %s\n", COLOR);
    printf("Format: %s\n", FORMAT);
    printf("QR code text:\n");
    printf("%s\n", qr_text);
    
    return 0;
}