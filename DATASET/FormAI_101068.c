//FormAI DATASET v1.0 Category: QR code generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {

    // Check that the correct number of arguments have been passed
    if (argc != 3) {
        printf("Error: Incorrect number of arguments.\n");
        printf("Usage: %s [QR code data] [output filename]\n", argv[0]);
        return -1;
    }

    // Assign the input data and output filename to variables
    char *qrData = argv[1];
    char *outputFilename = argv[2];

    // Generate the QR code using the qrencode library
    QRcode *qr = QRcode_encodeString(qrData, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Open the output file for writing
    FILE *fp;
    fp = fopen(outputFilename, "wb");

    // Check that the file was successfully opened
    if (fp == NULL) {
        printf("Error: Unable to open output file %s for writing.\n", outputFilename);
        return -1;
    }

    // Write the QR code to the output file
    int x, y;
    for (y = 0; y < qr->width; y++) {
        for (x = 0; x < qr->width; x++) {
            fwrite((qr->data[y * qr->width + x] & 1) ? "\033[48;5;0m  \033[0m" : "\033[48;5;255m  \033[0m", 1, 12, fp);
        }
        fprintf(fp, "\n");
    }

    // Close the output file
    fclose(fp);

    // Free the QR code data
    QRcode_free(qr);

    printf("QR code has been generated and written to file %s.\n", outputFilename);

    return 0;
}