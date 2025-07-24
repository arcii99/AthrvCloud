//FormAI DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3
#define HEADER_SIZE 54
#define MAX_FILE_SIZE 1000000

void hideDataInImage(char *imagePath, char *dataPath){
    FILE *imageFile = fopen(imagePath, "rb+");
    FILE *dataFile = fopen(dataPath, "rb");

    if (imageFile == NULL){
        printf("Image file could not be opened!\n");
        return;
    }

    if (dataFile == NULL){
        printf("Data file could not be opened!\n");
        return;
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);

    if (imageSize < HEADER_SIZE){
        printf("Invalid image file!\n");
        return;
    }

    fseek(imageFile, 0, SEEK_SET);

    unsigned char *imageData = (unsigned char*)malloc(imageSize * sizeof(unsigned char));

    fread(imageData, sizeof(unsigned char), imageSize, imageFile);

    // Extract image properties from the header
    int width = *(int*)&imageData[18];
    int height = *(int*)&imageData[22];
    int bitsPerPixel = *(short*)&imageData[28];

    if (bitsPerPixel != BYTES_PER_PIXEL*8){
        printf("Unsupported format!\n");
        return;
    }

    int dataSize = 0;
    char *dataStr = (char*)malloc(MAX_FILE_SIZE);
    memset(dataStr, 0, MAX_FILE_SIZE);

    while(fgets(&dataStr[dataSize], MAX_FILE_SIZE - dataSize, dataFile)){
        dataSize = strlen(dataStr);
    }

    if (dataSize + HEADER_SIZE > imageSize){
        printf("Insufficient space in image file!\n");
        return;
    }

    // Write data size first
    memcpy(&imageData[HEADER_SIZE], &dataSize, sizeof(dataSize));

    // Write data after header
    memcpy(&imageData[HEADER_SIZE + sizeof(dataSize)], dataStr, dataSize);

    fseek(imageFile, 0, SEEK_SET);
    fwrite(imageData, sizeof(unsigned char), imageSize, imageFile);

    fclose(imageFile);
    fclose(dataFile);

    printf("Data hidden successfully!\n");
}

void extractDataFromImage(char *imagePath){
    FILE *imageFile = fopen(imagePath, "rb");

    if (imageFile == NULL){
        printf("Image file could not be opened!\n");
        return;
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);

    if (imageSize < HEADER_SIZE){
        printf("Invalid image file!\n");
        return;
    }

    fseek(imageFile, HEADER_SIZE, SEEK_SET);

    int dataSize = 0;
    fread(&dataSize, sizeof(int), 1, imageFile);

    if (dataSize <= 0){
        printf("No data found in image file!\n");
        return;
    }

    char *dataStr = (char*)malloc(dataSize * sizeof(char));

    fread(dataStr, sizeof(char), dataSize, imageFile);

    printf("Extracted Data from Image: \n%s\n", dataStr);

    fclose(imageFile);
}

int main(){
    char *imagePath = "image.bmp";
    char *dataPath = "data.txt";

    hideDataInImage(imagePath, dataPath);

    extractDataFromImage(imagePath);

    return 0;
}