//FormAI DATASET v1.0 Category: QR code reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_qr(char* code) {
    int length = strlen(code);
    if (length != 101) { // QR code must have exactly 101 characters
        return 0;
    }
    if (code[0] != 'C' || code[1] != '-') { // QR code must start with "C-"
        return 0; 
    }
    for (int i = 2; i < length; i++) { // remaining characters must be uppercase letters or digits
        if (!(code[i] >= 'A' && code[i] <= 'Z') && !(code[i] >= '0' && code[i] <= '9')) {
            return 0;
        }
    }
    return 1; // QR code passed all checks
}

int main() {
    printf("Please scan the QR code:\n");
    char input[102];
    fgets(input, 102, stdin); // read user input
    input[strcspn(input, "\n")] = 0; // remove newline character from input
    if (check_qr(input)) {
        printf("QR code accepted!\n");
    } else {
        printf("Invalid QR code format. Please try again.\n");
    }
    return 0;
}