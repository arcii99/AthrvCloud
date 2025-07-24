//FormAI DATASET v1.0 Category: QR code reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_valid_char(char c) {
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    if (c == '.' || c == ' ' || c == '$' || c == '/' || c == '+' || c == '%')
        return true;
    return false;
}

int main() {
    char qr_code[101];
    // Maximum QR code length is 100 characters
    printf("Please enter the QR code:\n");
    scanf("%100[^\n]", qr_code); // Read up to 100 characters or until a newline is encountered
    
    int count = 0;
    for (int i = 0; qr_code[i] != '\0'; i++) {
        if (!is_valid_char(qr_code[i])) {
            printf("Invalid QR code!\n");
            return 0;
        }
        count++;
    }
    if (count > 0) {
        printf("QR code read successfully!\n");
        printf("QR code: %s\n", qr_code);
    }
    return 0;
}