//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    printf("Welcome to the C QR code generator program!\n");

    // Getting the input string to generate the QR code for
    char inputStr[100];
    printf("Enter the string to generate QR code for: ");
    scanf("%s", &inputStr);

    // Converting the input string to a QR code
    QRcode* qrCode = QRcode_encodeString(inputStr, 0, QR_ECLEVEL_H, QR_MODE_8, 1);

    // Printing the QR code as a matrix of asterisks
    printf("QR code for %s:\n", inputStr);
    for (int i=0; i<qrCode->width; i++) {
        for (int j=0; j<qrCode->width; j++) {
            if (qrCode->data[i*qrCode->width+j] & 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Freeing the memory allocated for the QR code
    QRcode_free(qrCode);

    printf("Thanks for using the C QR code generator program!\n");
    return 0;
}