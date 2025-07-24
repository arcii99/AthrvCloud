//FormAI DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [string]\n", argv[0]);
        return 0;
    }
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("QRcode encoding failed.\n");
        return 1;
    }
    int width = qrcode->width;
    int height = qrcode->width + 4;
    char *buffer = calloc(width * height, sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    char *ptr = buffer;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            *ptr++ = ' ';
        }
        *ptr++ = '\n';
    }
    ptr = buffer;
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            if (qrcode->data[i * qrcode->width + j] & 1) {
                buffer[(j + 2) * height + i + 2] = '#';
            }
        }
    }
    printf("%s\n", buffer);
    QRcode_free(qrcode);
    free(buffer);
    return 0;
}