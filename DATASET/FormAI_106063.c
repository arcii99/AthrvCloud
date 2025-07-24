//FormAI DATASET v1.0 Category: QR code generator ; Style: systematic
#include <stdio.h>
#include <qrencode.h>

int main() {
    // Declare the variables
    QRcode *qr;
    int i, j, width = 0;
    unsigned char *row, *p;
    const unsigned char *text = "Hello, world!";

    // Generate QR code
    qr = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Get the width of the QR code
    width = qr->width;

    // Loop through each row of the QR code
    for(i=0; i<width; i++) {
        // Get the row data
        row = qr->data+i*qr->width;

        // Loop through each column of the QR code
        for(j=0, p=row; j<width; j++, p++) {
            // Print out the QR code
            printf("%c%c", (*p & 1) ? ' ' : '.', (*p & 2) ? '.' : ' ');
        }

        // Print out a newline character after each row
        printf("\n");
    }

    // Free the QR code and exit the program
    QRcode_free(qr);

    return 0;
}