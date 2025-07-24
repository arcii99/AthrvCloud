//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CODE_SIZE 100

// A shape shifting QR code reader example program

int main()
{
    char qr_code[MAX_CODE_SIZE];
    int code_size = 0;
    bool is_round = false;
    bool is_square = false;
    bool is_triangle = false;

    // Read QR code
    printf("Enter QR code: ");
    scanf("%s", qr_code);

    // Determine code type and size
    for (int i = 0; qr_code[i] != '\0'; i++) {
        code_size++;
        if (qr_code[i] == 'o') {
            is_round = true;
        } else if (qr_code[i] == 's') {
            is_square = true;
        } else if (qr_code[i] == 't') {
            is_triangle = true;
        }
    }

    // Shape shift the QR code
    if (is_round) {
        printf("Shape shifted QR code: circle\n");
    } else if (is_square) {
        printf("Shape shifted QR code: square\n");
    } else if (is_triangle) {
        printf("Shape shifted QR code: triangle\n");
    } else {
        printf("Unknown QR code type.\n");
    }

    // Print QR code info
    printf("QR code size: %d\n", code_size);

    return 0;
}