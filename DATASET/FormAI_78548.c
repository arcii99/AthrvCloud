//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <text to encode>\n", argv[0]);
        return 1;
    }

    QRcode *qr_code = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr_code == NULL) {
        printf("Could not encode text: %s\n", argv[1]);
        return 1;
    }

    printf("QR code for \"%s\":\n", argv[1]);
    for (int y = 0; y < qr_code->width; y++) {
        for (int x = 0; x < qr_code->width; x++) {
            if (qr_code->data[y * qr_code->width + x] & 1) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    QRcode_free(qr_code);

    return 0;
}