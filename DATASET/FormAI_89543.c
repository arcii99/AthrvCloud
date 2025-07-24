//FormAI DATASET v1.0 Category: QR code reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 256
#define QR_CODE_PREFIX "CQR:"

bool read_qr_code(char *input, char *code) {
    int prefix_length = strlen(QR_CODE_PREFIX);
    if (strncmp(input, QR_CODE_PREFIX, prefix_length) != 0) {
        return false;
    }
    int code_length = strlen(input) - prefix_length;
    if (code_length > MAX_CODE_LENGTH) {
        return false;
    }
    strncpy(code, input + prefix_length, code_length);
    code[code_length] = '\0';
    return true;
}

int main() {
    char input[256];
    char code[MAX_CODE_LENGTH + 1];
    printf("Enter a QR code: ");
    fgets(input, sizeof(input), stdin);
    if (read_qr_code(input, code)) {
        printf("QR code found: %s\n", code);
    } else {
        printf("Invalid QR code\n");
    }
    return 0;
}