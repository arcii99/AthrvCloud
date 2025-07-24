//FormAI DATASET v1.0 Category: QR code generator ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        // If there is no input message, print an error message and exit program
        fprintf(stderr, "Usage: %s 'message'\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Define qrencode configuration parameters
    int version = 0;
    QRcode *qr = NULL;
    unsigned char *data = (unsigned char *) argv[1];

    // Generate QR code based on input message
    qr = QRcode_encodeString((char *) data, 0, QR_ECLEVEL_L, QR_MODE_8, version);

    // Check if QR code was successfully generated
    if (qr == NULL) {
        fprintf(stderr, "Could not generate QR code\n");
        return EXIT_FAILURE;
    }

    // Print QR code ASCII art to the console
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            printf("%c", qr->data[y * qr->width + x] ? 'X' : ' ');
        }
        printf("\n");
    }

    // Free memory allocated for QR code
    QRcode_free(qr);

    return EXIT_SUCCESS;
}