//FormAI DATASET v1.0 Category: QR code generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include "qrencode.h"

int main(int argc, char *argv[]) {
    int version = 0;
    int level = QR_ECLEVEL_L;
    const char *data = "Hello, world!";
    QRcode *qrcode;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s output-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "wb")) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    qrcode = QRcode_encodeString(data, version, level, QR_MODE_8, 1);

    if (qrcode == NULL) {
        fprintf(stderr, "QRcode encoding failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            fprintf(fp, "%c", qrcode->data[i*qrcode->width+j] ? '1' : '0');
        }
        fprintf(fp, "\n");
    }

    QRcode_free(qrcode);
    fclose(fp);
    return 0;
}