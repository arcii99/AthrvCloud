//FormAI DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
    printf("Enter the text to encode: ");

    char text[256];
    scanf("%s", text);

    QRcode *qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        printf("Error: Failed to encode QR code.\n");
        return 1;
    }

    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            int value = qr->data[y * qr->width + x];
            if (value == 0) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    QRcode_free(qr);

    return 0;
}