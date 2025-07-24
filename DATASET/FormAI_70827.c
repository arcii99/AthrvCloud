//FormAI DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

int main(int argc, char *argv[]) {
    // Get the input data from the command line argument
    if (argc != 2) {
        printf("Usage: %s input_data\n", argv[0]);
        return 1;
    }
    char *data = argv[1];

    // Generate the QR code
    QRcode *qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        printf("Error: Failed to generate QR code\n");
        return 1;
    }

    // Print the QR code to the console
    int width = qrcode->width;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", qrcode->data[i * width + j] ? '#' : ' ');
        }
        printf("\n");
    }

    // Free the QR code memory
    QRcode_free(qrcode);

    return 0;
}