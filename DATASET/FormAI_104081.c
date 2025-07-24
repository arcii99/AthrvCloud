//FormAI DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main()
{
    int size = 5; //QR code size
    int margin = 2; //QR code margin

    QRcode* code;

    char* qr_data = "Hello, World!"; //text to encode

    code = QRcode_encodeString(qr_data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    printf("QR Code:\n");

    for (int y = 0; y < code->width + margin * 2; y++)
    {
        for (int x = 0; x < code->width + margin * 2; x++)
        {
            if (x < margin || x >= code->width + margin || y < margin || y >= code->width + margin)
            {
                printf("#"); //print margin
            }
            else if (code->data[(y - margin) * code->width + (x - margin)] & 1)
            {
                printf("X"); //print black pixel
            }
            else
            {
                printf(" "); //print white pixel
            }
        }
        printf("\n");
    }

    QRcode_free(code);

    return 0;
}