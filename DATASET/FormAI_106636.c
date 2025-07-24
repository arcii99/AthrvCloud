//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <qrencode.h>

int main(void) {
    char *string = "I am a unique QR code!";
    QRcode *qr = QRcode_encodeString(string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    if (qr != NULL) {
        for (int i = 0; i < qr->width + 4; i++) {
            printf("=");
        }
        printf("\n");

        for (int i = 0; i < qr->width; i++) {
            printf("||");
            for (int j = 0; j < qr->width; j++) {
                if (qr->data[i * qr->width + j] & 1) {
                    printf("  ");
                } else {
                    printf("##");
                }
            }
            printf("||\n");
        }

        for (int i = 0; i < qr->width + 4; i++) {
            printf("=");
        }
        printf("\n");

        QRcode_free(qr);
    }

    return 0;
}