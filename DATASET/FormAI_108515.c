//FormAI DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <qrencode.h>
#include <stdlib.h>

int main()
{
    // User's input
    char string[256];
    printf("Enter a string to generate a QR code:\n");
    scanf("%s", string);

    // Encode the string into a QR code
    QRcode* qr;
    qr = QRcode_encodeString(string, 0, QR_ECLEVEL_H, QR_MODE_8, 1);

    // Display the QR code in the console
    for(int i=0; i<qr->width+4; i++) printf("X");
    printf("\n");
    for(int i=0; i<qr->width; i++)
    {
        printf("X  ");
        for(int j=0; j<qr->width; j++)
        {
            if(qr->data[i*qr->width+j] & 1) printf("  ");
            else printf("X ");
        }
        printf("  X\n");
    }
    for(int i=0; i<qr->width+4; i++) printf("X");
    printf("\n");

    // Free the QR code
    QRcode_free(qr);

    return 0;
}