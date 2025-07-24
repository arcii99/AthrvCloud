//FormAI DATASET v1.0 Category: QR code reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Welcome to the C QR code reader program!\n\n");

    // First, we will generate a random QR code to read.
    char qrCode[21];
    for (int i = 0; i < 20; i++) {
        qrCode[i] = 'A' + (rand() % 26);
    }
    qrCode[20] = '\0';
    printf("Generated QR code: %s\n\n", qrCode);

    // Now, we will ask the user to input a QR code to read.
    char input[21];
    printf("Please enter the QR code to read (20 characters max): ");
    scanf("%s", input);

    // Check that the input code is valid (20 characters).
    if (strlen(input) != 20) {
        printf("\nInvalid QR code: must be exactly 20 characters.\n");
        return 1;
    }

    // Compare the input code with the generated code.
    if (strcmp(input, qrCode) == 0) {
        printf("\nQR code read successfully!\n");
    } else {
        printf("\nQR code invalid: does not match generated code.\n");
    }

    return 0;
}