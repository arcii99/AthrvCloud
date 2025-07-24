//FormAI DATASET v1.0 Category: QR code generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide data to encode.\n");
        return 1;
    }

    const char *data = argv[1];

    // Generate QR code
    QRcode *qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qr == NULL) {
        printf("Failed to generate QR code.\n");
        return 1;
    }

    // Print QR code as ASCII art
    const int WIDTH = qr->width;
    const int HEIGHT = qr->width;
    const uint8_t *module = qr->data;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            const uint8_t value = module[y * WIDTH + x];
            printf(value ? "##" : "  ");
        }

        printf("\n");
    }

    // Free QR code
    QRcode_free(qr);

    return 0;
}