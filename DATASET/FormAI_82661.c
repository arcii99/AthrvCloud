//FormAI DATASET v1.0 Category: QR code generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    // check if the input is valid
    if (argc < 2) {
        printf("Please enter a string to convert to QR code\n");
        exit(1);
    }
    // get the input string
    char *input_string = argv[1];
    // create QR code
    QRcode *qrcode = QRcode_encodeString(input_string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    // check if QR code was successfully created
    if (qrcode == NULL) {
        printf("Failed to create QR code\n");
        exit(1);
    }
    // print the QR code to the console
    int width = qrcode->width;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            if (qrcode->data[i * width + j] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    // free memory
    QRcode_free(qrcode);

    return 0;
}