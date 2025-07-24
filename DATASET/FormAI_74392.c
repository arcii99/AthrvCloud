//FormAI DATASET v1.0 Category: QR code generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    // check if user has provided a string to encode
    if (argc < 2) {
        printf("Please provide a string to convert to QR code.\n");
        return 1;
    }

    // create QR code
    QRcode *qr;
    const char *str = argv[1];
    qr = QRcode_encodeString(str, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // print QR code ASCII art
    int size = qr->width;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf((qr->data[i*size+j]&1)?"  ":"██");
        }
        printf("\n");
    }

    QRcode_free(qr);
    return 0;
}