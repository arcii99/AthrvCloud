//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    char *text = "https://www.example.com";
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if(qrcode == NULL) {
        printf("Error: Failed to generate QR code.\n");
        return EXIT_FAILURE;
    }

    int width = qrcode->width;
    int height = qrcode->width;

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(qrcode->data[y * width + x] & 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    return EXIT_SUCCESS;
}