//FormAI DATASET v1.0 Category: QR code generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_SIZE 25
#define MAX_ROWS 10
#define MAX_COLUMNS 10

char qrCode[MAX_ROWS][MAX_COLUMNS];

void generateQRCode();
void printQRCode();
void printQRBinary();

int main()
{
    srand(time(NULL));

    printf("Generating QR Code...\n");
    generateQRCode();

    printf("\nQR Code Generated:\n");
    printQRCode();

    printf("\nQR Code in Binary Form:\n");
    printQRBinary();

    return 0;
}

void generateQRCode()
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLUMNS; j++)
        {
            int randomDigit = rand() % 10;
            qrCode[i][j] = randomDigit + '0';
        }
    }
}

void printQRCode()
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLUMNS; j++)
        {
            printf("%c ", qrCode[i][j]);
        }
        printf("\n");
    }
}

void printQRBinary()
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLUMNS; j++)
        {
            printf("%d", qrCode[i][j] - '0');
        }
        printf("\n");
    }
}