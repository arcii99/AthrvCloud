//FormAI DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    // Generate QR code
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Save QR code to file
    FILE *fp = fopen("qrcode.png", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }
    fwrite(qrcode->data, qrcode->width, qrcode->width, fp);
    fclose(fp);

    // Free memory used by QR code
    QRcode_free(qrcode);

    printf("QR code generated and saved to qrcode.png\n");
    return 0;
}