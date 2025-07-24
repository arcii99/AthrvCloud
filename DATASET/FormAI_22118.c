//FormAI DATASET v1.0 Category: QR code generator ; Style: Dennis Ritchie
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_VERSION 40
#define MAX_QR_DIMENSIONS (MAX_QR_VERSION * 4 + 17)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    int text_len = strlen(text);
    if (text_len == 0) {
        printf("Error: text cannot be empty.\n");
        return EXIT_FAILURE;
    }

    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Error: failed to generate QR code.\n");
        return EXIT_FAILURE;
    }

    if (qrcode->version > MAX_QR_VERSION) {
        printf("Error: QR code version too high for default configuration.\n");
        return EXIT_FAILURE;
    }

    int qr_dimensions = qrcode->width;
    if (qr_dimensions > MAX_QR_DIMENSIONS) {
        printf("Error: QR code dimensions too large for default configuration.\n");
        return EXIT_FAILURE;
    }

    for (int y = 0; y < qr_dimensions; y++) {
        for (int x = 0; x < qr_dimensions; x++) {
            int is_black = qrcode->data[y * qr_dimensions + x] & 1;
            printf(is_black ? "##" : "  ");
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    return EXIT_SUCCESS;
}