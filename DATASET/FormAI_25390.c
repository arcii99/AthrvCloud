//FormAI DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 25
#define MAX_INPUT_SIZE 200

void generate_code(char* input);

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Please enter a string (max %d characters): ", MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    generate_code(input);

    return 0;
}

void generate_code(char* input) {
    int length = strlen(input);
    int code[QR_SIZE][QR_SIZE];

    // Initialize code with 0s
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            code[i][j] = 0;
        }
    }

    // Fill in the code with the input string and some random noise
    for (int i = 0; i < length; i++) {
        int row = i / QR_SIZE;
        int col = i % QR_SIZE;
        code[row][col] = input[i] + rand() % 2;
    }
    for (int i = length; i < QR_SIZE * QR_SIZE; i++) {
        int row = i / QR_SIZE;
        int col = i % QR_SIZE;
        code[row][col] = rand() % 2;
    }

    // Print out the QR code
    printf("QR code for '%s':\n", input);
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (code[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}