//FormAI DATASET v1.0 Category: QR code generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, const char *argv[]) {

    // check command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"string\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    // create QR code object
    QRcode *qr;
    int version = 0;
    int level = QR_ECLEVEL_L;  // error correction level
    
    // encode string as QR code
    qr = QRcode_encodeString(argv[1], version, level, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Error: Failed to create QR code from string.\n");
        return EXIT_FAILURE;
    }

    // print QR code to console
    printf("\n");
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("\033[47m  \033[0m");  // white block
            } else {
                printf("\033[40m  \033[0m");  // black block
            }
        }
        printf("\n");
    }
    printf("\n");

    // free QR code object
    QRcode_free(qr);

    return EXIT_SUCCESS;
}