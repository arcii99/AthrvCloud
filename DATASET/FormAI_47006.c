//FormAI DATASET v1.0 Category: QR code generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    // Check if user input argument is available
    if (argc < 2) {
        printf("Usage: %s [string to encode]\n", argv[0]);
        return 1;
    }

    // Get user input string
    char *input_string = argv[1];

    // Generate QR code
    QRcode *qr_code = QRcode_encodeString(input_string, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

    // Check if QR code generation was successful
    if (qr_code == NULL) {
        printf("Error generating QR code.\n");
        return 1;
    }

    // Print QR code in terminal
    int width = qr_code->width;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            if (qr_code->data[i * width + j] & 1) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }

    // Free memory used for QR code generation
    QRcode_free(qr_code);

    return 0;
}