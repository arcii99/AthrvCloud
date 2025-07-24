//FormAI DATASET v1.0 Category: QR code generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Please enter a string to generate the QR code!\n");
        return 0;
    }

    // Get the input string from the command line arguments
    char *input = argv[1];

    // Initialize the QR code generation module
    QRcode *qrCode = QRcode_encodeString(input, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

    // Print the generated QR code
    for (int i = 0; i < qrCode->width + 4; i++) {
        printf("\033[33;40m*\033[0m");
    }
    printf("\n");

    for(int i = 0; i < qrCode->width; i++) {
        for(int j = 0; j < qrCode->width; j++) {
            if(qrCode->data[j * qrCode->width + i] & 1) {
                printf("\033[33;40m  \033[0m");
            } else {
                printf("\033[40;40m  \033[0m");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < qrCode->width + 4; i++) {
        printf("\033[33;40m*\033[0m");
    }
    printf("\n");

    // Free the QR code object
    QRcode_free(qrCode);

    return 0;
}