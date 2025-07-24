//FormAI DATASET v1.0 Category: QR code generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main()
{
    char text[256];
    QRcode *qrcode;
    int i, j;
    FILE *fp;
    unsigned char *byte;
    const char filename[] = "qrcode.png";

    printf("Enter text to generate QR code: ");
    fgets(text, sizeof(text), stdin);

    byte = (unsigned char *) malloc(strlen(text) + 1);
    strcpy((char *) byte, text);

    // Generate QR code from text
    qrcode = QRcode_encodeString((const char *) byte, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Open file to write QR code image
    fp = fopen(filename, "wb");

    // Write QR code image to file
    for (i = 0; i < qrcode->width; i++) {
        for (j = 0; j < qrcode->width; j++) {
            fputc(qrcode->data[i * qrcode->width + j] ? ' ' : '\x1b', fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
    QRcode_free(qrcode);
    free(byte);

    printf("QR code generation successful\n");

    return 0;
}