//FormAI DATASET v1.0 Category: QR code generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s message\n", argv[0]);
        return -1;
    }
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Failed to encode message.\n");
        return -1;
    }
    FILE *file = fopen("qrcode.png", "wb");
    if (file == NULL) {
        printf("Failed to create output file.\n");
        return -1;
    }
    fwrite(qrcode->data, qrcode->width * qrcode->width, 1, file);
    fclose(file);
    printf("QR code saved as qrcode.png.\n");
    return 0;
}