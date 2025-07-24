//FormAI DATASET v1.0 Category: QR code reader ; Style: romantic
#include <stdio.h>
#include <qrencode.h>

int main() {
    // Initialize QR code object
    QRcode *qr;

    // Prompt user to enter QR code string
    printf("Enter the QR code string: ");
    char qrString[100];
    fgets(qrString, 100, stdin);

    // Generate QR code for given string
    qr = QRcode_encodeString(qrString, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

    // Print QR code as romantic poem
    printf("\nAs I scan this QR code, it reveals\n");
    printf("A message from you, my dear, that feels\n");
    printf("Like a million butterflies dancing in my heart,\n");
    printf("A love that will never, ever fall apart.\n");
    printf("\n");

    // Print QR code in ASCII art style
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }

    // Free memory allocated for QR code
    QRcode_free(qr);

    return 0;
}