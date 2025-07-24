//FormAI DATASET v1.0 Category: QR code generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {

    int qr_version = 3;     // version of QR code
    int qr_errorlevel = 1;  // error correction level
    QRcode *qr;             // QR code pointer
    char *qr_data;          // QR code data string
    int qr_length;          // length of data string
    int i, j;

    // user input
    char *input_data = malloc(sizeof(char) * 256);
    printf("Enter data string to encode: ");
    scanf("%s", input_data);

    // get length of data string
    qr_length = strlen(input_data);

    // generate QR code
    qr_data = malloc(sizeof(char) * qr_length);
    strcpy(qr_data, input_data);
    qr = QRcode_encodeString(qr_data, qr_version, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    // print QR code to terminal
    for (i=0; i<qr->width; i++) {
        for (j=0; j<qr->width; j++) {
            if (qr->data[i*qr->width+j] & 0x01) {
                printf("\033[40m  ");
            } else {
                printf("\033[47m  ");
            }
        }
        printf("\033[0m\n");
    }

    // free memory
    QRcode_free(qr);
    free(qr_data);
    free(input_data);

    return 0;
}