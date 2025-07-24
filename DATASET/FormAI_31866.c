//FormAI DATASET v1.0 Category: QR code reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isQRCode(char code[]) {
    // check if the given string starts with "QR-"
    if (code[0] != 'Q' || code[1] != 'R' || code[2] != '-') {
        return false;
    }

    // check if the subsequent characters are digits
    for (int i = 3; code[i] != '\0'; i++) {
        if (code[i] < '0' || code[i] > '9') {
            return false;
        }
    }

    return true;
}

char* readCode() {
    char* code = (char*) malloc(10 * sizeof(char)); // allocate 10 bytes of memory for the code
    printf("Enter QR code: ");
    scanf("%s", code);
    return code;
}

int main() {
    char* code = readCode();

    if (isQRCode(code)) {
        printf("Valid QR code: %s\n", code);
        // process the QR code
    } else {
        printf("Invalid QR code: %s\n", code);
    }

    free(code); // release the allocated memory
    return 0;
}