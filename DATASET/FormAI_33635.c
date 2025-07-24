//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

void generateQRCode(char* text) {
    QRcode* code = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    int width = code->width;
    unsigned char *image = (unsigned char*) malloc(width * width * 3 * sizeof(unsigned char));
    unsigned char *p = image;

    for(int y = 0; y < width; y++) {
        for(int x = 0; x < width; x++) {
            unsigned char color = 255 - code->data[y * width + x];
            *(p++) = color;
            *(p++) = color;
            *(p++) = color;
        }
    }

    QRcode_free(code);

    FILE *fp;
    fp = fopen("qrcode.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, width);
    fwrite(image, width * width * 3, 1, fp);
    fclose(fp);

    free(image);
}

int main() {
    char* text = "Hello, world!";
    generateQRCode(text);

    return 0;
}