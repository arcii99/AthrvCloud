//FormAI DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    QRcode *qr;
    unsigned char *data;
    int i, j, width;

    if (argc != 2) {
        printf("Usage: qr <string>\n");
        exit(EXIT_FAILURE);
    }

    data = (unsigned char*)argv[1];
    qr = QRcode_encodeString((char*)data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    width = qr->width;

    for (i = 0; i < width + 4; i++) {
        printf("██");
    }
    printf("\n");

    for (i = 0; i < width; i++) {
        printf("████");
        for (j = 0; j < width; j++) {
            if (qr->data[i * width + j] & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("████\n");
    }

    for (i = 0; i < width + 4; i++) {
        printf("██");
    }
    printf("\n");

    QRcode_free(qr);
    return 0;
}