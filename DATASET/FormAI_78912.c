//FormAI DATASET v1.0 Category: QR code generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define QR_WIDTH 21

void printQRCode(char qrCode[][QR_WIDTH + 1], int size);

int main()
{
    // User input
    char input[100];
    printf("Enter the text to encode:\n");
    scanf("%s", input);

    // QR code generation
    char qrCode[QR_WIDTH][QR_WIDTH];
    for (int i = 0; i < QR_WIDTH; i++) {
        for (int j = 0; j < QR_WIDTH; j++) {
            qrCode[i][j] = ' ';
        }
    }
    int current = 0;
    for (int i = 1; i < QR_WIDTH - 1; i++) {
        for (int j = 1; j < QR_WIDTH - 1; j++) {
            qrCode[i][j] = input[current];
            current++;
            if (current >= strlen(input)) {
                break;
            }
        }
        if (current >= strlen(input)) {
            break;
        }
    }
    printQRCode(qrCode, QR_WIDTH);

    return 0;
}

void printQRCode(char qrCode[][QR_WIDTH + 1], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%s\n", qrCode[i]);
    }
}