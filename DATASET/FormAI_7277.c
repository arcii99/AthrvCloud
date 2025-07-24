//FormAI DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "qrencode.h"

int main(int argc, char* argv[])
{
    QRcode* qr;
    uint8_t* data;
    char* qrText = "QR CODE EXAMPLE";
    int qrVersion = 3; // QR Code version ranges from 1-40, larger means more data capacity and larger QR code image

    int i, j;
    qr = QRcode_encodeString(qrText, 0, QR_ECLEVEL_M, QR_MODE_8, 1);
    data = qr->data;

    // Iterate through the QR code's data
    for (i = 0; i < qr->width; i++) {
        for (j = 0; j < qr->width; j++) {
            // Print a black square for a '1' and a white square for a '0'
            printf("%c", (*data & (1 << j)) ? '#' : ' ');
        }
        printf("\n");
        data += qr->width;
    }

    QRcode_free(qr);
    return 0;
}