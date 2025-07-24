//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // Check if the user has provided the necessary arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [DATA] [OUTPUT FILE PATH]\n", argv[0]);
        return -1;
    }

    // Initialize the QR code version to be used
    QRcode *qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Create a file handle for writing the QR code to a file
    FILE *file = fopen(argv[2], "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to create file %s\n", argv[2]);
        return -1;
    }

    // Write the QR code data to the file in ASCII format
    unsigned char *row_data = qr->data;
    for (int i = 0; i < qr->width; i++) {
        for (int j = 0; j < qr->width; j++) {
            if ((row_data[j / 8] & (1 << (7 - (j % 8)))) != 0) {
                fprintf(file, "  ");
            } else {
                fprintf(file, "\u2588\u2588");
            }
        }
        row_data += qr->width / 8;
        fprintf(file, "\n");
    }

    // Clean up resources
    QRcode_free(qr);
    fclose(file);

    printf("QR code generated and saved to file %s\n", argv[2]);
    return 0;
}