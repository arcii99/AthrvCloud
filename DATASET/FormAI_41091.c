//FormAI DATASET v1.0 Category: QR code generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        printf("Error: Usage should be of the form './qrgen [string to encode]'\n");
        return 1;
    }

    // Create a QRcode object
    QRcode *qrcode;
    qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Generate the QR code image
    int size = qrcode->width;
    unsigned char *image_data = (unsigned char*)malloc(size * size * 3);
    unsigned char *ptr = image_data;
    for (int i = 0; i < size * size; i++) {
        *ptr++ = qrcode->data[i] & 1 ? 0 : 255;
        *ptr++ = qrcode->data[i] & 1 ? 0 : 255;
        *ptr++ = qrcode->data[i] & 1 ? 0 : 255;
    }

    // Print the QR code image to the command line
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(image_data[(i * size + j) * 3] ? " " : "\u2588");
        }
        printf("\n");
    }

    // Free memory and return
    free(image_data);
    QRcode_free(qrcode);
    return 0;
}