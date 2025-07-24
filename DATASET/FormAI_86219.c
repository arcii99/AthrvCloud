//FormAI DATASET v1.0 Category: QR code generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    QRcode *myQRcode = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    int i, j;
    // print out the QR code to console
    for(i=0; i < myQRcode->width; i++) {
        for(j=0; j < myQRcode->width; j++) {
            if(myQRcode->data[i*myQRcode->width+j] & 1) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }
    QRcode_free(myQRcode);
    return 0;
}