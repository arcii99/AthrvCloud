//FormAI DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 100
#define QR_CODE_VALID "QR Code Valid"
#define QR_CODE_INVALID "QR Code Invalid"

bool isQRCodeValid(char* code) {
    if (strlen(code) != 20) {
        return false;
    }
    for(int i = 0; i < 20; i++) {
        if (code[i] < 'A' || code[i] > 'Z') {
            return false;
        }
    }
    return true;
}

int main() {
    char code[MAX_CODE_LENGTH];
    printf("Enter a 20-character QR code:\n");
    fgets(code, MAX_CODE_LENGTH, stdin);

    if(isQRCodeValid(code)) {
        printf(QR_CODE_VALID);
    }
    else {
        printf(QR_CODE_INVALID);
    }
    
    return 0;
}