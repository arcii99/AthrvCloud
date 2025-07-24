//FormAI DATASET v1.0 Category: QR code generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    QRcode *qrcode;
    unsigned char *data;
    int version, width;
    int i, j;

    if (argc != 2) {
        fprintf(stderr, "usage: %s string-to-encode\n", argv[0]);
        return 1;
    }

    qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    width = qrcode->width;
    data = qrcode->data;

    printf("\n\nQR Code:\n\n");

    for (i = 0; i < width; i++) {
        for (j = 0; j < width; j++) {
            if (*data & 1) {
                printf("  ");
            } else {
                printf("██");
            }
            ++data;
        }
        printf("\n");
    }

    QRcode_free(qrcode);

    return 0;
}