//FormAI DATASET v1.0 Category: QR code generator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    char qrCode[25][25];
    int i, j;

    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
            qrCode[i][j] = (rand() % 2) + '0';
        }
    }

    printf("\n\nQR Code Generator\n");

    for(i=0;i<25;i++)
    {
        printf("\n");

        for(j=0;j<25;j++)
        {
            printf("%c ",qrCode[i][j]);
        }
    }

    printf("\n");

    return 0;
}