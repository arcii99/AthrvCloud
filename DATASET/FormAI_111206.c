//FormAI DATASET v1.0 Category: QR code generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char input[MAX_SIZE];
    int length, i, j, index = 0;
    int binary[8] = {0};
    char QRcode[MAX_SIZE];

    printf("Enter your text: ");
    fgets(input, MAX_SIZE, stdin);

    length = strlen(input);

    for (i = 0; i < length; i++)
    {
        // Convert each character in the input into its binary equivalent
        for (j = 7; j >= 0; j--)
        {
            binary[j] = (input[i] & 1);
            input[i] = input[i] >> 1;
        }

        // Append the binary digits to the QRcode string
        for (j = 0; j < 8; j++)
        {
            QRcode[index++] = (binary[j] == 1) ? '1' : '0';
        }
    }

    QRcode[index] = '\0';

    // Print the generated QR code
    printf("\nGenerated QR code: %s\n", QRcode);

    return 0;
}