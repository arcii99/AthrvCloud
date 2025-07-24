//FormAI DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text to encode>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // define QR code parameters
    int margin = 0;
    int version = 1; 
    int level = QR_ECLEVEL_L;
    int hint = QR_MODE_8;

    // create QR code object
    QRcode *code = QRcode_encodeString(argv[1], margin, level, hint, version);

    // print QR code
    int width = code->width;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            if (code->data[y * width + x] & 1) {
                printf("\033[40m  ");
            } else {
                printf("\033[47m  ");
            }
        }
        printf("\033[0m\n"); // reset terminal color
    }

    // free QR code object
    QRcode_free(code);

    return 0;
}