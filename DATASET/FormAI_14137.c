//FormAI DATASET v1.0 Category: QR code reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid QR code
bool isValidQRCode(char *input) {
    int length = strlen(input);
    if (length < 21 || length > 43) {
        return false;
    }
    if (input[0] != 'Q' || input[1] != 'R') {
        return false;
    }
    for (int i = 2; i < length - 6; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    if (input[length - 5] != '-' || input[length - 3] != '-') {
        return false;
    }
    for (int i = length - 4; i < length; i++) {
        if (!isalpha(input[i]) || isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[50];
    printf("Enter a QR code: ");
    scanf("%s", input);
    if (isValidQRCode(input)) {
        printf("Valid QR code!\n");
        // Here you can add additional functionality for processing the QR code
    } else {
        printf("Not a valid QR code.\n");
    }
    return 0;
}