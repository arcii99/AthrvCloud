//FormAI DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) { // check number of arguments
        printf("Usage: %s <text> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *text = argv[1];
    char *filename = argv[2];
    
    QRcode *qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1); // generate QR code
    
    FILE *fp = fopen(filename, "wb"); // create file to write QR code to
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return EXIT_FAILURE;
    }
    
    for (int y = 0; y < qr->width; y++) { // loop through QR code and write to file
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                fprintf(fp, "%c%c", 0x2588, 0x2588);
            } else {
                fprintf(fp, "  ");
            }
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    QRcode_free(qr); // free memory
    
    return EXIT_SUCCESS;
}