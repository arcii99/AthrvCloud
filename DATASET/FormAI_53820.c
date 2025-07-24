//FormAI DATASET v1.0 Category: QR code reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to check if the QR code is valid
bool isValidQR(char* code) {
    int length = strlen(code);
    int i = 0;
    
    // check if the length is 25, starts with "CQR-", and ends with ".png"
    if (length == 29 && strncmp(code, "CQR-", 4) == 0 && strncmp(code + length - 4, ".png", 4) == 0) {
        // check if the remaining characters are alphanumeric
        for (i = 4; i < length - 4; i++) {
            if (!isalnum(code[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    char qrCode[30];
    
    // ask user to input QR code
    printf("Please enter the QR code: ");
    scanf("%s", qrCode);
    
    // check if QR code is valid
    if (isValidQR(qrCode)) {
        // open QR code image and read contents
        
        // print contents of QR code
        printf("The contents of the QR code are: ...\n");
        
    } else {
        printf("Invalid QR code.\n");
    }
    
    return 0;
}