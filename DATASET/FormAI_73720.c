//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char **argv)
{
    // Check that data was provided
    if (argc < 2) {
        printf("Error: please provide data as an argument.\n");
        return -1;
    }

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Print QR code to console
    for (int i = 0; i < qrcode->width + 4; i++) {
        printf("▄");
    }
    printf("\n");
    for (int i = 0; i < qrcode->width; i++) {
        printf("▐");
        for (int j = 0; j < qrcode->width; j++) {
            printf("%c%c", qrcode->data[i*qrcode->width+j]?' ':'▀', qrcode->data[i*qrcode->width+j]?' ':' ');
        }
        printf("▌\n");
    }
    for (int i = 0; i < qrcode->width + 4; i++) {
        printf("▀");
    }
    printf("\n");

    // Free memory
    QRcode_free(qrcode);

    return 0;
}