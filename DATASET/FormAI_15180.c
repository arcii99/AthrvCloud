//FormAI DATASET v1.0 Category: QR code generator ; Style: portable
#include <stdio.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <content> <output_file>\n", argv[0]);
        return 0;
    }

    int size = 10;

    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", argv[2]);
        QRcode_free(qrcode);
        return 1;
    }

    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            unsigned char color = qrcode->data[y*qrcode->width + x] & 1 ? 255 : 0;
            fprintf(fp, "%c%c%c", color, color, color);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    QRcode_free(qrcode);

    printf("QR Code generated in file: %s\n", argv[2]);

    return 0;
}