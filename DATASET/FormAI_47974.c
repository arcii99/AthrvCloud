//FormAI DATASET v1.0 Category: QR code reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main()
{
    char qr_code_input[100];
    int version = -1, width = 0;
    int qr_size = 0;
    printf("Enter QR code string: ");
    fgets(qr_code_input, sizeof(qr_code_input), stdin);
    qr_size = strlen(qr_code_input);

    if(qr_size > 0)
    {
        if(qr_size > 32)
        {
            version = 6;
            width = 33;
        }
        else if(qr_size > 26)
        {
            version = 5;
            width = 29;

        }
        else if(qr_size > 20)
        {
            version = 4;
            width = 25;
        }
        else if(qr_size > 16)
        {
            version = 3;
            width = 21;
        }
        else if(qr_size > 10)
        {
            version = 2;
            width = 17;
        }
        else
        {
            version = 1;
            width = 13;
        }

        QRcode *qr_code = QRcode_encodeString(qr_code_input, 0, QR_ECLEVEL_L, QR_MODE_8, version);
        if(qr_code == NULL)
            printf("Error: Cannot generate QR code.\n");
        else
        {
            for(int i = 0; i < (width+8); i++)
                printf("*");
            printf("\n");
            for(int i = 0; i < qr_code->width; i++)
            {
                for(int j = 0; j < 4; j++)
                    putchar('*');
                for(int j = 0; j < qr_code->width; j++)
                {
                    if(*((qr_code->data) + (i * qr_code->width) + j) & 1)
                        printf(" ");
                    else
                        printf("*");
                }
                for(int j = 0; j < 4; j++)
                    putchar('*');
                putchar('\n');
            }
            for(int i = 0; i < (width+8); i++)
                printf("*");
            printf("\n");
            QRcode_free(qr_code);
        }
    }
}