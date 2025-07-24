//FormAI DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    // Get input string from user
    char input[256];
    printf("Enter the string to encode as a QR code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    // Generate QR code
    QRcode *qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Print QR code to console
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free memory used by QR code
    QRcode_free(qr);

    return 0;
}