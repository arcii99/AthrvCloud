//FormAI DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Please input the text you want to encode!");
        return 1;
    }

    char *text = argv[1];

    QRcode *qrcode;
    qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if(qrcode == NULL) {
        printf("Failed to generate QR Code!");
        return 1;
    }

    int width = qrcode->width;
    unsigned char *img = qrcode->data;

    FILE *file;
    file = fopen("qrcode.pgm", "wb");

    fprintf(file, "P5\n%d %d\n255\n", width, width);

    for(int i = 0; i < width * width; i++) {
        if(img[i] & 1) {
            fputc(0, file);
        } else {
            fputc(255, file);
        }
    }

    fclose(file);
    QRcode_free(qrcode);

    printf("QR Code generated successfully");

    return 0;
}