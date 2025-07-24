//FormAI DATASET v1.0 Category: QR code reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a valid QR code
bool isValidQRCode(char *code) {
    if (strlen(code) != 21) {   // QR code has 21 characters
        return false;
    }
    
    for (int i = 0; i < 21; i++) {   // check if all characters are alphanumeric
        if (!((code[i] >= '0' && code[i] <= '9') || (code[i] >= 'A' && code[i] <= 'Z'))) {
            return false;
        }
    }
    
    // QR code is valid
    return true;
}

int main() {
    char code[21];
    printf("Enter QR code: ");
    scanf("%s", code);
    
    if (!isValidQRCode(code)) {   // check if code is valid
        printf("Invalid QR code!\n");
        return 1;
    }
    
    // TODO: Implement QR code reader functionality here
    
    printf("QR code read successfully!\n");
    return 0;
}