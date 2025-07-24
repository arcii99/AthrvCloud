//FormAI DATASET v1.0 Category: QR code generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include "qrencode.h"

//define size of QR Code
#define QR_VERSION 7

//define error message for segmentation faults
#define ERROR_SEG_FAULT "Error: Segmentation Fault"

//Main function for generating QR Code
int main(int argc, char *argv[]) {
    //check if user inputs data
    if (argc != 2) {
        fprintf(stderr,"Usage: %s 'data to be encoded'\n", argv[0]);
        return EXIT_FAILURE;
    }

    //Generate QR Code and save it in pixel array
    QRcode *qrcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_H, QR_MODE_8, 1);
    
    //Check for segmentation faults
    if (!qrcode) {
        fprintf(stderr, ERROR_SEG_FAULT);
        return EXIT_FAILURE;
    }

    //iterate over pixel array to print QR Code
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            putchar(qrcode->data[y*qrcode->width+x]?'#':' ');
        }
        putchar('\n');
    }

    //Free memory allocated for QR Code
    QRcode_free(qrcode);

    return EXIT_SUCCESS;
}