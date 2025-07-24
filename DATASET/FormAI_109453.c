//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to convert binary to decimal
int binaryToDecimal(char *binaryString) {
    int decimal = 0, i, j, length;
    length = strlen(binaryString);
    for(i=0;i<length;i++) {
        j = length-i-1;
        if(binaryString[i] == '1') {
            decimal += 1 << j;
        }
    }
    return decimal;
}

// function to convert decimal to binary
char* decimalToBinary(int decimal) {
    int i, j;
    char *binaryString = (char*) malloc (sizeof(char) * 9);
    for(i=7;i>=0;i--) {
        j = decimal >> i;
        binaryString[7-i] = j % 2 == 0 ? '0' : '1';
    }
    binaryString[8] = '\0';
    return binaryString;
}

// compression function
char* compressImage(char *imageData, int imageLength) {
    char *compressedData = (char*) malloc (sizeof(char) * imageLength/8);
    char *temp;
    int i, j, k=0, decimal;
    for(i=0;i<imageLength;i+=8) {
        temp = (char*) malloc (sizeof(char) * 9);
        for(j=0;j<8;j++) {
            temp[j] = imageData[i+j];
        }
        decimal = binaryToDecimal(temp);
        compressedData[k++] = decimal;
        free(temp);
    }
    return compressedData;
}

// decompression function
char* decompressImage(char *compressedData, int compressedLength, int imageLength) {
    char *decompressedData = (char*) malloc (sizeof(char) * imageLength);
    char *temp;
    char *binaryString;
    int i, j, k=0;
    for(i=0;i<compressedLength;i++) {
        binaryString = decimalToBinary(compressedData[i]);
        for(j=0;j<8;j++) {
            decompressedData[k++] = binaryString[j];
        }
        free(binaryString);
    }
    return decompressedData;
}

int main() {
    char imageData[] = "0101010100101010010101001010101001010101010101010010101001010101010101010101010101010101010101010010101010010101001010101001010";
    int imageDataLength = strlen(imageData);
    printf("Image data: %s\n", imageData);
    char *compressedData = compressImage(imageData, imageDataLength);
    int compressedDataLength = imageDataLength/8 + (imageDataLength%8 ? 1 : 0);
    printf("Compressed data: ");
    for(int i=0;i<compressedDataLength;i++) {
        printf("%d ", compressedData[i]);
    }
    printf("\n");
    char *decompressedData = decompressImage(compressedData, compressedDataLength, imageDataLength);
    printf("Decompressed data: %s", decompressedData);
    free(compressedData);
    free(decompressedData);
    return 0;
}