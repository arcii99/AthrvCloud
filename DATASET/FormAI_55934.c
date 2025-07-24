//FormAI DATASET v1.0 Category: QR code reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_qr(char* qr_code) {
    if (strlen(qr_code) != 16) {
        return false;
    }
    for (int i = 0; i < 16; i++) {
        if (qr_code[i] < 'A' || qr_code[i] > 'Z') {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Welcome to the QR Code Reader 2.0!\n");
    printf("Please scan your CQR code below:\n");

    char qr_code[50];
    scanf("%s", qr_code);

    if (is_valid_qr(qr_code)) {
        printf("CQR code scanned successfully\n");
        printf("Access granted to confidential area\n");
    } else {
        printf("Invalid CQR code. Try again.\n");
    }

    return 0;
}