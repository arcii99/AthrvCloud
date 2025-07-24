//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "qrencode.h"

#define QR_VERSION 7     // QR code version
#define QR_LEVEL   'M'   // QR code error correction level
#define QR_SCALE   4     // QR code pixel size

void printQrCode(QRcode *code) {
    printf("\n");
    for (int i = 0; i < code->width+4; i++) {
        printf("*");  // print border
    }
    printf("\n");
    for (int i = 0; i < code->width; i++) {
        printf("**"); // print border
        for (int j = 0; j < code->width; j++) {
            if (code->data[i*code->width+j]&1) printf("  ");
            else printf("##");
        }
        printf("**\n");  // print border
    }
    for (int i = 0; i < code->width+4; i++) {
        printf("*");  // print border
    }
    printf("\n");
}

int main(int argc, char **argv) {

    char qrString[100];
    printf("Enter the text to be encoded in QR code: ");
    scanf("%[^\n]%*c", qrString);

    QRcode *code = QRcode_encodeString(qrString, QR_VERSION, QR_LEVEL, QR_MODE_8, 1);

    if (code == NULL) {
        printf("Error: failed to encode QR code\n");
        exit(EXIT_FAILURE);
    }

    printf("QR code generated:\n");
    printQrCode(code);

    QRcode_free(code);
    return 0;
}