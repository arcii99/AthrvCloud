//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    QRcode *qr;
    
    /* check if command line arguments are correct */
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* generate QR code */
    qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    /* print QR code */
    for (int y = 0; y < qr->width + 2; y++) {
        printf("\033[107m  ");
    }
    printf("\n");
    for (int y = 0; y < qr->width; y++) {
        printf("\033[107m  ");
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("\033[40m  ");
            } else {
                printf("\033[107m  ");
            }
        }
        printf("\033[107m  \n");
    }
    for (int y = 0; y < qr->width + 2; y++) {
        printf("\033[107m  ");
    }
    printf("\033[0m\n");
    
    /* free QR code */
    QRcode_free(qr);
    
    return EXIT_SUCCESS;
}