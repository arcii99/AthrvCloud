//FormAI DATASET v1.0 Category: QR code generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(void) {
    char message[100];
    QRcode *qrcode;

    printf("Enter your message: ");
    scanf("%s", message);

    qrcode = QRcode_encodeString(message, 0, QR_ECLEVEL_M, QR_MODE_8, 1);

    if (qrcode == NULL) {
        printf("Error: Could not generate QR code.\n");
        return 1;
    }

    printf("QR code:\n");
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->width; j++) {
            char *data = (qrcode->data + j*qrcode->width+i);
            if (*data & 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    return 0;
}