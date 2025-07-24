//FormAI DATASET v1.0 Category: QR code generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [url] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    QRcode *qr;
    int version = 5; // default QR code version
    int level = QR_ECLEVEL_L; // default error correction level
    int casesensitive = 1; // case sensitive mode (1:on, 0:off)

    // encode the URL into a QR code
    qr = QRcode_encodeString(argv[1], version, level, QR_MODE_8, casesensitive);

    // create a binary file to store the generated QR code
    FILE *fp;
    fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error: unable to create file\n");
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    // write the QR code to the file
    fwrite(qr->data, qr->width * qr->width, 1, fp);

    // close the file and free memory
    fclose(fp);
    QRcode_free(qr);

    return 0;
}