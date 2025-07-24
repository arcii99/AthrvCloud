//FormAI DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 200

bool is_valid_qr_code(const char* code) {
    // QR code must start with "QR-"
    if (strncmp(code, "QR-", 3) != 0) {
        return false;
    }

    // QR code must not exceed maximum length
    if (strlen(code) > MAX_QR_CODE_LENGTH) {
        return false;
    }

    // QR code must only contain alphanumeric characters
    for (int i = 3; i < strlen(code); i++) {
        char c = code[i];
        if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            return false;
        }
    }

    return true;
}

int main() {
    char qr_code[MAX_QR_CODE_LENGTH+1];
    printf("Please enter a QR code: ");
    scanf("%s", qr_code);

    if (is_valid_qr_code(qr_code)) {
        printf("Valid QR code!\n");
    } else {
        printf("Invalid QR code.\n");
    }

    return 0;
}