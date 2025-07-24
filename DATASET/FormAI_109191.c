//FormAI DATASET v1.0 Category: QR code reader ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_SIZE 100

typedef struct qr_code {
    int size;
    char data[MAX_QR_CODE_SIZE];
} QRCode;

bool readQRCode(QRCode *code) {
    printf("Please scan the QR code: ");

    if(scanf("%s", code->data) == 1) {
        code->size = strlen(code->data);
        printf("QR code scanned successfully!\n");
        return true;
    } else {
        printf("Failed to scan the QR code!\n");
        return false;
    }
}

void displayQRCode(QRCode *code) {
    printf("-------------------------\n");
    printf("QR code data:\n%s\n", code->data);
    printf("QR code size: %d bytes\n", code->size);
    printf("-------------------------\n");
}

int main(int argc, char *argv[]) {
    QRCode code;
    memset(&code, 0, sizeof(code));

    while(true) {
        if(readQRCode(&code)) {
            displayQRCode(&code);
        }
    }

    return EXIT_SUCCESS;
}