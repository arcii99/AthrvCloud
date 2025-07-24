//FormAI DATASET v1.0 Category: QR code generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // Check that an input string was provided 
    if (argc < 2) {
        printf("Usage: %s [string to encode]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Encode the string using QRCode library
    QRcode *qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Print out the QR code matrix
    int i, j;
    for (i = 0; i < qr->width + 2; i++) {
        putchar('#');
    }
    putchar('\n');

    for (i = 0; i < qr->width; i++) {
        putchar('#');
        for (j = 0; j < qr->width; j++) {
            if (qr->data[i * qr->width + j] & 1) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('#');
        putchar('\n');
    }

    for (i = 0; i < qr->width + 2; i++) {
        putchar('#');
    }
    putchar('\n');

    // Free allocated memory
    QRcode_free(qr);

    return 0;
}