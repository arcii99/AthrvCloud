//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    char *data = "Hello, world!"; // Your data here
    QRcode *qr;
    int i, j, width = 0;

    // Generate QR code
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Error generating QR code\n");
        return 1;
    }

    // Calculate width of QR code
    for (i=0; i<qr->width; i++) {
        if (qr->data[i*qr->width] == 0) {
            width = i+1;
        }
    }

    // Print QR code
    printf("\n");
    for (i=0; i<width; i++) {
        for (j=0; j<width; j++) {
            if (qr->data[i*width+j] == 0) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");

    // Free memory
    QRcode_free(qr);

    return 0;
}