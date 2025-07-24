//FormAI DATASET v1.0 Category: QR code generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include "qrencode.h"

int main(int argc, char *argv[])
{
    int i;
    QRcode *qrcode;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [string to encode]\n", argv[0]);
        return 1;
    }

    qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "QR code generation failed.\n");
        return 1;
    }

    for (i = 0; i < qrcode->width + 4; i++)
        printf("##");
    printf("\n");

    for (i = 0; i < qrcode->width; i++) {

        printf("##");

        int j;
        for (j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i*qrcode->width+j]&1)
                printf("  ");
            else
                printf("##");
        }

        printf("##");
        printf("\n");
    }

    for (i = 0; i < qrcode->width + 4; i++)
        printf("##");
    printf("\n");

    QRcode_free(qrcode);

    return 0;
}