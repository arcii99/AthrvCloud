//FormAI DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

int main(void) {
    char* data = "Hello, world!"; // Replace with the data you want to encode
    QRcode* qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        printf("Error encoding QR code\n");
        return 1;
    }

    printf("QR code size: %dx%d\n", qr->width, qr->width);

    // Loop through each row and column of the QR code to print
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 0x01) {
                printf("██"); // Print a black square
            } else {
                printf("  "); // Print an empty space
            }
        }
        printf("\n"); // Move to next row
    }

    QRcode_free(qr); // Free memory allocated for QR code

    return 0;
}