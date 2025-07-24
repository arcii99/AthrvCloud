//FormAI DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    QRcode *qrCode;

    // Get user input
    printf("Enter text to generate QR code: ");
    scanf("%[^\n]", input);

    // Generate QR code
    qrCode = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Create PNG image file
    FILE *pngFile;
    pngFile = fopen("qrcode.png", "wb");
    fwrite(qrCode->data, qrCode->width, qrCode->width, pngFile);
    fclose(pngFile);

    // Clean up
    QRcode_free(qrCode);

    printf("QR code generated and saved as qrcode.png!");

    return 0;
}