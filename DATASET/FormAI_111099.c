//FormAI DATASET v1.0 Category: QR code reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_SIZE 21 // Size of a QR code version 1
#define BUFFER_SIZE 100 // Maximum size of the input buffer

/* Function to check if the input is a valid QR code */
bool isQRCode(char *input)
{
    /* Check for input length */
    if (strlen(input) != QR_CODE_SIZE) {
        return false;
    }

    /* Check for input characters: alphanumeric + "-" */
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        if (!(isalnum(input[i]) || input[i] == '-')) {
            return false;
        }
    }

    /* Check for the "QRCode" prefix */
    if (strncmp("QRCode", input, 6) != 0) {
        return false;
    }

    /* If all checks pass, then it's a valid QR code */
    return true;
}

int main()
{
    char buffer[BUFFER_SIZE];

    /* Get input from the user */
    printf("Enter a QR code: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    /* Remove the newline character from the input buffer */
    buffer[strcspn(buffer, "\n")] = '\0';

    /* Check if the input is a valid QR code */
    if (isQRCode(buffer)) {
        printf("Valid QR code!\n");
    } else {
        printf("Invalid QR code!\n");
    }

    return 0;
}