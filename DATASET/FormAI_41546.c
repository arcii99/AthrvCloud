//FormAI DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to convert decimal to binary
void decToBinary(int decimal, char binary[])
{
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[index] = '\0';
}

// Function to convert binary to decimal
int binaryToDec(char binary[])
{
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int main()
{
    char originalText[MAX_SIZE];
    char secretText[MAX_SIZE];
    printf("Enter the original text: ");
    fgets(originalText, MAX_SIZE, stdin);
    printf("Enter the secret text: ");
    fgets(secretText, MAX_SIZE, stdin);
    
    // Convert secret text to binary
    char binarySecret[MAX_SIZE * 8];
    int secretLength = strlen(secretText);
    int binaryIndex = 0;
    for (int i = 0; i < secretLength; i++) {
        decToBinary(secretText[i], &binarySecret[binaryIndex]);
        binaryIndex += 8;
    }
    
    // Get the LSB of each pixel in the original image
    char fileName[MAX_SIZE];
    printf("Enter the image file name: ");
    fgets(fileName, MAX_SIZE, stdin);
    FILE *imageFile = fopen(fileName, "r");
    unsigned char pixel, lsb;
    int count = 0;
    while (fread(&pixel, sizeof(pixel), 1, imageFile)) {
        lsb = pixel & 0x01;
        if (count <= binaryIndex) {
            lsb = binarySecret[count];
            count++;
        }
        printf("%c", (lsb == '0' ? ' ' : '#'));
    }
    fclose(imageFile);
    
    return 0;
}