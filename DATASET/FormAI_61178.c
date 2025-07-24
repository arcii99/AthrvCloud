//FormAI DATASET v1.0 Category: QR code reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define QR code struct
typedef struct QRcode {
    char data[100];
} QRcode;

// function to read QR code
bool readQRcode(QRcode* code) {
    printf("Please scan the QR code: ");
    fgets(code->data, 100, stdin);
    if (code->data[strlen(code->data) - 1] == '\n') {
        code->data[strlen(code->data) - 1] = '\0';
    }
    return true;
}

int main() {
    QRcode code;
    bool valid = false;

    while (!valid) {
        valid = readQRcode(&code);
        if (!valid) {
            printf("Invalid QR code, please try again.\n");
        }
    }

    printf("QR code scanned successfully!\n");
    printf("Data: %s\n", code.data);

    return 0;
}