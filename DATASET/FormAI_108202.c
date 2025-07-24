//FormAI DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define MAX_INPUT_SIZE 100

int main()
{
    printf("Enter the data which you want to convert to QR Code: ");
    char input[MAX_INPUT_SIZE];
    fgets(input, sizeof(input), stdin);

    // Remove newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Generate the QR Code
    QRcode *qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Print the QR Code
    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            if (qr->data[y * qr->width + x] & 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free the QR Code memory
    QRcode_free(qr);

    return 0;
}