//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [string to encode]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *string_to_encode = argv[1];

    // Create a QR code
    QRcode *qr_code = QRcode_encodeString(string_to_encode, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr_code == NULL) {
        fprintf(stderr, "Error: Failed to encode string: %s\n", string_to_encode);
        return EXIT_FAILURE;
    }

    // Display the QR code
    int width = qr_code->width;
    unsigned char *row = qr_code->data;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (*row & 0x1) {
                printf("██");
            } else {
                printf("  ");
            }
            row++;
        }
        printf("\n");
    }

    // Free memory
    QRcode_free(qr_code);

    return EXIT_SUCCESS;
}