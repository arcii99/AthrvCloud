//FormAI DATASET v1.0 Category: QR code generator ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char data[256];
    QRcode *qrcode;

    printf("Enter data to generate QR code: ");
    scanf("%s", data);

    qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    int width = qrcode->width;
    printf("\nQR code width: %d\n", width);

    printf("\nQR code:\n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            int index = j * width + i;
            printf(qrcode->data[index] ? "  " : "\u2588\u2588");
        }
            printf("\n");
    }

    QRcode_free(qrcode);

    return 0;
}