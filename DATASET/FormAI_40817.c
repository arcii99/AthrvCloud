//FormAI DATASET v1.0 Category: QR code reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char data[1024];
} QRCode;

bool scanQRCode(QRCode* code) {
    printf("Ready to scan QR code. Please hold the code in front of the camera.\n");

    // code scanning implementation
    // ...

    printf("QR code scanning completed!\n");
    strcpy(code->data, "<data extracted from QR code>");
    return true;
}

int main() {
    QRCode code;
    bool scanned = scanQRCode(&code);

    if (scanned) {
        printf("QR code data is: %s\n", code.data);
    } else {
        printf("Failed to scan QR code.\n");
    }

    return 0;
}