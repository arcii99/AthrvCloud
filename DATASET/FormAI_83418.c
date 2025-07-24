//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_LEN 1000

void embedMessage(const char* inputFilename, const char* outputFilename, const char* message) {
    FILE* inputFile = fopen(inputFilename, "rb");
    FILE* outputFile = fopen(outputFilename, "wb");

    if (!inputFile || !outputFile) {
        printf("Failed to open file.");
        return;
    }

    unsigned char buffer;
    int messageLen = strlen(message);
    int bitPos = 0;

    while (fread(&buffer, 1, 1, inputFile)) {
        if (bitPos < messageLen * 8) {
            unsigned char newBuffer = buffer & 0xFE;
            newBuffer |= ((message[bitPos / 8] >> (bitPos % 8)) & 0x1);
            fwrite(&newBuffer, 1, 1, outputFile);
            bitPos++;
        }
        else {
            fwrite(&buffer, 1, 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Message embedded successfully!");
}

int main() {
    char inputFilename[] = "input.jpg";
    char outputFilename[] = "output.jpg";
    char message[MAX_MESSAGE_LEN];

    printf("Enter message to embed: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);

    embedMessage(inputFilename, outputFilename, message);

    return 0;
}