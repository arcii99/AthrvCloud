//FormAI DATASET v1.0 Category: QR code reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 42

bool isQRCode(char* input) {
    if (strlen(input) != MAX_CODE_LENGTH) {
        return false;
    }
    const char* prefix = "QRCode:";
    if (strncmp(input, prefix, strlen(prefix)) != 0) {
        return false;
    }
    for (int i = strlen(prefix); i < strlen(input); i++) {
        if (input[i] != '0' && input[i] != '1') {
            return false;
        }
    }
    return true;
}

void readQRCode(char* code) {
    printf("Please scan your QR code: \n");
    scanf("%s", code);
}

void displayQRCode(char* code) {
    printf("Your code is: %s \n", code);
}

int main() {
    char code[MAX_CODE_LENGTH];
    do {
        readQRCode(code);
        if (isQRCode(code)) {
            displayQRCode(code);
        } else {
            printf("Invalid QR code. Please try again. \n");
        }
    } while (true);
    return 0;
}