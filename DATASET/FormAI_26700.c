//FormAI DATASET v1.0 Category: QR code generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    // Check if the right number of arguments is passed
    if (argc != 3) {
        printf("Usage: ./qr_code_generator [text] [filename.png]\n");
        return -1;
    }

    // Encode the text into a QR code
    QRcode *qr_code = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Create a file to write the QR code to
    FILE *file = fopen(argv[2], "wb");

    // Check if file was opened successfully
    if (!file) {
        printf("Error: Could not create the file %s.\n", argv[2]);
        QRcode_free(qr_code);
        return -1;
    }

    // Write the QR code to the file
    fwrite(qr_code->data, sizeof(unsigned char), qr_code->width * qr_code->width, file);

    // Clean up
    fclose(file);
    QRcode_free(qr_code);
    printf("QR code successfully generated.\n");

    return 0;
}