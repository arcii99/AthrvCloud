//FormAI DATASET v1.0 Category: QR code reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CODE_LENGTH 100

bool is_valid_code(char* code) {
    // Check if the code follows the QR code format
    if (strlen(code) != 21 || code[0] != 'C' || code[1] != '-') {
        return false;
    }
    for (int i=2; i<strlen(code); i++) {
        if (!isdigit(code[i])) {
            return false;
        }
    }
    return true;
}

void read_code(char* code) {
    printf("Please scan the QR code:\n");
    scanf("%s", code);
}

int main() {
    char code[MAX_CODE_LENGTH];
    bool is_valid = false;
    while (!is_valid) {
        read_code(code);
        is_valid = is_valid_code(code);
        if (!is_valid) {
            printf("Invalid QR code. Please try again.\n");
        }
    }
    printf("Success! The QR code %s was successfully scanned.\n", code);
    return 0;
}