//FormAI DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int count = 0;

void generateQRCode(char code[], int index, char currChar)
{
    if (index == 0)
    {
        code[count] = '\0';
        printf("QR Code: %s\n", code);
        count++;
        return;
    }

    code[count] = currChar;
    generateQRCode(code, index-1, '0');
    generateQRCode(code, index-1, '1');
}

int main()
{
    char code[MAX_SIZE];
    int length;

    printf("Enter length of QR code: ");
    scanf("%d", &length);

    generateQRCode(code, length, '0');
    generateQRCode(code, length, '1');

    return 0;
}