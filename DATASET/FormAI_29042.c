//FormAI DATASET v1.0 Category: QR code reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_qr_code(char *code) {
    int len = strlen(code);
    if (len != 25) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if ((code[i] < 'A' || code[i] > 'F') && (code[i] < '0' || code[i] > '9')) {
            return false;
        }
    }
    return true;
}

void read_qr_code(char *code) {
    printf("Please scan your QR code: ");
    scanf("%s", code);
    while (!is_qr_code(code)) {
        printf("Invalid QR code. Please try again: ");
        scanf("%s", code);
    }
}

int main() {
    char qr_code[26];
    read_qr_code(qr_code);
    printf("QR code %s has been successfully read!", qr_code);
    return 0;
}