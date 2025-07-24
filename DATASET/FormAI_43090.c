//FormAI DATASET v1.0 Category: QR code generator ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]){
    const char *input = "Hello, world!";
    QRcode *qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if(!qrcode) {
        fprintf(stderr, "ERROR: Failed to encode QR Code\n");
        return EXIT_FAILURE;
    }

    int width = qrcode->width > 0 ? qrcode->width : 1;
    int height = qrcode->width > 0 ? qrcode->width : 1;

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            char c = qrcode->data[y * width + x] ? '#' : ' ';
            putchar(c);
        }
        putchar('\n');
    }

    QRcode_free(qrcode);

    return EXIT_SUCCESS;
}