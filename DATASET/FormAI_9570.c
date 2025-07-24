//FormAI DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char *qr_text = "https://www.example.com"; // Text to encode
    int qr_version = 6; // QR code version
    QRcode *qr = QRcode_encodeString(qr_text, 0, QR_ECLEVEL_Q, QR_MODE_8, 1); // Generate QR code data
    if (qr != NULL) {
        uint8_t *qr_data = qr->data;
        int qr_size = qr->width;

        // Print QR code to console
        for (int i = 0; i < qr_size; i++) {
            for (int j = 0; j < qr_size; j++) {
                if (*qr_data & 1) {
                    printf("  ");
                } else {
                    printf("\u2588\u2588");
                }
                qr_data++;
            }
            printf("\n");
        }

        QRcode_free(qr); // Free QR code data
    }

    return 0;
}