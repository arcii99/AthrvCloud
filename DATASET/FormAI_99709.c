//FormAI DATASET v1.0 Category: QR code generator ; Style: portable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

// Function to generate QR Code
void generateQRCode(char qrCode[MAX_SIZE][MAX_SIZE], int qrSize, char content[MAX_SIZE])
{
    // Initialize all cells to empty space
    for(int i=0; i<qrSize; i++)
    {
        for(int j=0; j<qrSize; j++)
        {
            qrCode[i][j] = ' ';
        }
    }

    // Encode the content
    for(int i=0; i<strlen(content); i++)
    {
        int AsciiVal = (int)content[i];

        for(int j=0; j<8; j++)
        {
            int bitVal = (AsciiVal>>(7-j)) & 1;

            if(bitVal == 1)
            {
                qrCode[i][j] = '#';
            }
            else
            {
                qrCode[i][j] = ' ';
            }
        }
    }

    // Print the QR Code
    printf("QR Code:\n");
    for(int i=0; i<qrSize; i++)
    {
        for(int j=0; j<qrSize; j++)
        {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char qrCode[MAX_SIZE][MAX_SIZE];
    int qrSize = 8;
    char content[MAX_SIZE];

    printf("Enter content to generate QR Code:\n");
    fgets(content, MAX_SIZE, stdin);

    // Remove the newline character from the content
    content[strcspn(content, "\n")] = 0;

    generateQRCode(qrCode, qrSize, content);

    return 0;
}