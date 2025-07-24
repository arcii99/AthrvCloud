//FormAI DATASET v1.0 Category: QR code reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum code length
#define MAX_LENGTH 100

// Define QR code struct
typedef struct QrCode {
    char code[MAX_LENGTH];
} QrCode;

// Define function to check if QR code is valid
bool is_valid_code(QrCode code) {
    int length = strlen(code.code);
    if (length != 11) { // QR code should have exactly 11 characters
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (code.code[i] < '0' || code.code[i] > '9') { // QR code should only contain digits
            return false;
        }
    }
    return true;
}

int main() {
    printf("Welcome to the QR code reader program, my dear Watson.\n");
    printf("Please input the QR code that you would like to scan: ");
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);
    QrCode code;
    strncpy(code.code, input, MAX_LENGTH);

    if (is_valid_code(code)) {
        printf("Excellent, Watson! This looks like a valid QR code.\n");
        printf("The code you scanned is: %s", code.code);
    } else {
        printf("I am sorry, Watson. This does not look like a valid QR code.\n");
        printf("May I suggest you scan a different code?\n");
    }

    return 0;
}