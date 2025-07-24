//FormAI DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to print bitmap file header */
void printBitmapFileHeader(unsigned char* data){
    int i;
    printf("Type: %c%c\n", data[0], data[1]);
    printf("Size: %d\n", *(int*)&data[2]);
    printf("Reserved 1: %d\n", *(int*)&data[6]);
    printf("Reserved 2: %d\n", *(int*)&data[10]);
    printf("Offset to pixels: %d\n", *(int*)&data[14]);
}

/* Function to print bitmap info header */
void printBitmapInfoHeader(unsigned char* data){
    int i;
    printf("Size of Header: %d\n", *(int*)&data[0]);
    printf("Width: %d\n", *(int*)&data[4]);
    printf("Height: %d\n", *(int*)&data[8]);
    printf("No. of Color Planes: %d\n", *(short*)&data[12]);
    printf("Bits per Pixel: %d\n", *(short*)&data[14]);
    printf("Compression Type: %d\n", *(int*)&data[16]);
    printf("Size of Image: %d\n", *(int*)&data[20]);
    printf("Horizontal Resolution: %d\n", *(int*)&data[24]);
    printf("Vertical Resolution: %d\n", *(int*)&data[28]);
    printf("No. of Colors: %d\n", *(int*)&data[32]);
    printf("No. of Important Colors: %d\n", *(int*)&data[36]);
}

int main(){
    FILE *fp;
    fp = fopen("test.bmp", "rb");
    if(fp == NULL){
        printf("Error: Unable to Open File.\n");
        return 0;
    }

    unsigned char* data;
    data = (unsigned char*)malloc(sizeof(unsigned char) * 54);
    fread(data, sizeof(unsigned char), 54, fp);

    printBitmapFileHeader(data);
    printBitmapInfoHeader(data + 14);

    fclose(fp);
    return 0;
}