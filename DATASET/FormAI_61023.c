//FormAI DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>

//Data struct for our futuristic compression algorithm
typedef struct CompressionData{
    int origSize;   //Original size of data
    int compSize;   //Compressed size of data
    char* compData; //Pointer to compressed data
} CompressionData;

// Function that compresses the data
CompressionData compressData(char* origData, int origSize){

    //Perform compression algorithm

    CompressionData compData;
    compData.origSize = origSize;
    compData.compSize = origSize / 2;
    compData.compData = (char*) malloc(sizeof(char) * compData.compSize);

    // Copy first and last two bytes to compressed data
    for(int i=0;i<2;i++){
        compData.compData[i] = origData[i];
        compData.compData[(compData.compSize - 2) + i] = origData[(origSize - 2) + i];
    }

    //Copy middle 50% of data to compressed data
    int startIndex = (origSize / 4);
    for(int i=2;i<(compData.compSize - 2);i++){
        compData.compData[i] = origData[startIndex + i - 2];
    }

    return compData;
}

int main(){

    //Example data
    char data[] = "Hello, world! This is our futuristic compression algorithm!";

    //Compress data using our algorithm
    CompressionData compData = compressData(data, strlen(data));

    //Print original size, compressed size and compressed data
    printf("Original data: %d bytes\n", compData.origSize);
    printf("Compressed data: %d bytes\n", compData.compSize);
    printf("Compressed data: %s\n", compData.compData);

    return 0;
}