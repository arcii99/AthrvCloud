//FormAI DATASET v1.0 Category: QR code generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generateQRCode(char *data, int version, QRecLevel level, QRencodeMode hint, int casesensitive) {
    QRcode *qr;
    unsigned char *row, *p;
    int x, y, width;
    FILE *fp;

    qr = QRcode_encodeString(data, version, level, hint, casesensitive);
    if (qr == NULL) {
        printf("QRcode encoding failed\n");
        exit(1);
    }

    width = qr->width;
    row = (unsigned char *)malloc(width + 1);
    fp = fopen("qrcode.txt", "wb");
    if (fp == NULL) {
        printf("Failed to create qrcode.txt\n");
        exit(1);
    }

    for (y = 0; y < width; y++) {
        p = qr->data + y * width;
        for (x = 0; x < width; x++) {
            row[x] = (*p++ & 1) ? 'X' : ' ';
        }
        row[width] = '\0';
        fprintf(fp, "%s\n", row);
    }

    fclose(fp);
    QRcode_free(qr);
}

int main() {
    char *data = "https://example.com";
    int version = 2;
    QRecLevel level = QR_ECLEVEL_Q;
    QRencodeMode hint = QR_MODE_8;
    int casesensitive = 1;

    generateQRCode(data, version, level, hint, casesensitive);
    printf("QR code generated successfully\n");

    return 0;
}