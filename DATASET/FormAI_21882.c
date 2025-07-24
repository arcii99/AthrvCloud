//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define WATERMARK_SIZE 32
#define MAX_FILE_SIZE 10000

// Function to read binary file
int readBinaryFile(char* fileName, char* fileData) {
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL) {
        return -1;
    }
    
    int fileSize;
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);
    fread(fileData, sizeof(char), fileSize, fp);
    fclose(fp);
    return fileSize;
}

// Function to write binary file
void writeBinaryFile(char* fileName, char* fileData, int fileSize) {
    FILE* fp = fopen(fileName, "wb");
    fwrite(fileData, sizeof(char), fileSize, fp);
    fclose(fp);
}

// Function to generate random watermark
void generateWatermark(char* watermark) {
    srand(time(NULL));
    for(int i=0; i<WATERMARK_SIZE; i++) {
        watermark[i] = rand()%256;
    }
}

// Function to embed watermark into file
void embedWatermark(char* fileData, int fileSize, char* watermark) {
    int watermarkIndex = 0;
    for(int i=0; i<fileSize; i++) {
        if(watermarkIndex >= WATERMARK_SIZE) {
            break;
        }
        fileData[i] = fileData[i] | watermark[watermarkIndex];
        watermarkIndex++;
    }
}

// Function to extract watermark from file
void extractWatermark(char* fileData, int fileSize, char* watermark) {
    int watermarkIndex = 0;
    for(int i=0; i<fileSize; i++) {
        if(watermarkIndex >= WATERMARK_SIZE) {
            break;
        }
        watermark[watermarkIndex] = fileData[i] & 255;
        watermarkIndex++;
    }
}

// Main function
int main(int argc, char const *argv[]) {
    if(argc < 3) {
        printf("Usage: watermark <input_file> <output_file>\n");
        return -1;
    }

    char* inputFileName = argv[1];
    char* outputFileName = argv[2];

    char fileData[MAX_FILE_SIZE];
    int fileSize = readBinaryFile(inputFileName, fileData);
    if(fileSize <= 0) {
        printf("Error: could not read input file\n");
        return -1;
    }

    char watermark[WATERMARK_SIZE];
    generateWatermark(watermark);

    embedWatermark(fileData, fileSize, watermark);

    writeBinaryFile(outputFileName, fileData, fileSize);

    printf("Watermark embedded successfully\n");

    char extractedWatermark[WATERMARK_SIZE];
    int extractedFileSize = readBinaryFile(outputFileName, fileData);
    if(extractedFileSize <= 0) {
        printf("Error: could not read output file\n");
        return -1;
    }

    extractWatermark(fileData, extractedFileSize, extractedWatermark);

    if(memcmp(watermark, extractedWatermark, WATERMARK_SIZE) == 0) {
        printf("Watermark extracted successfully\n");
        return 0;
    } else {
        printf("Error: could not extract watermark\n");
        return -1;
    }
}