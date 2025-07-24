//FormAI DATASET v1.0 Category: QR code generator ; Style: rigorous
#include <stdio.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    // check if user input is valid
    if (argc < 2) {
        printf("Usage: %s 'message'\n", argv[0]);
        return 1;
    }

    // create QR code
    QRcode *qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_M, QR_MODE_8, 1);

    // check if QR code creation was successful
    if (qr == NULL) {
        printf("Failed to encode QR code.\n");
        return 1;
    }

    // output QR code as ASCII art
    int size = qr->width;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            printf("%c", qr->data[y * size + x] ? '*' : ' ');
        }
        printf("\n");
    }

    // free QR code
    QRcode_free(qr);

    return 0;
}