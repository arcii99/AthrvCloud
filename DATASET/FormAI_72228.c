//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void embedWatermark(char *inputFileName, char *outputFileName, char *watermark) {

    FILE *inputFilePtr, *outputFilePtr;
    char inputBuffer[MAX_LEN], outputBuffer[MAX_LEN];

    inputFilePtr = fopen(inputFileName, "r");
    outputFilePtr = fopen(outputFileName, "w");

    if (!inputFilePtr || !outputFilePtr) {
        printf("Error! Unable to open files.\n");
        return;
    }

    while (fgets(inputBuffer, MAX_LEN, inputFilePtr)) {
        // Embedding watermark in each line
        strcat(inputBuffer, watermark);
        strcpy(outputBuffer, inputBuffer);
        fputs(outputBuffer, outputFilePtr);
    }

    fclose(inputFilePtr);
    fclose(outputFilePtr);

    printf("Watermarking successful!\n");
}

int main() {
    char *inputFileName = "input.txt";
    char *outputFileName = "output.txt";
    char *watermark = "DIGITAL_WATERMARK";

    embedWatermark(inputFileName, outputFileName, watermark);
    return 0;
}