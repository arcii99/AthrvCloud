//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the size of a file in bytes
long int getFileSize(FILE *file) {
    // Seek to the end of the file
    fseek(file, 0, SEEK_END);
    // Get the size of the file
    long int size = ftell(file);
    // Seek back to the beginning of the file
    fseek(file, 0, SEEK_SET);
    return size;
}

// Function to create a digital watermark
void createWatermark(char *inputFile, char *outputFile, char *watermark) {
    // Open the input file
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        printf("Error: Could not open input file!\n");
        return;
    }
    
    // Open the output file
    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        printf("Error: Could not open output file!\n");
        fclose(inFile);
        return;
    }
    
    // Get the size of the input file
    long int fileSize = getFileSize(inFile);
    
    // Create the message that will hold the watermark and file size
    char message[1000];
    
    // Copy the watermark into the message
    strcpy(message, watermark);
    
    // Add the file size to the message
    sprintf(message + strlen(message), " %ld", fileSize);
    
    // Write the message to the output file
    fwrite(message, strlen(message), 1, outFile);
    
    // Copy the contents of the input file to the output file
    char buffer[1000];
    while (fread(buffer, 1, sizeof(buffer), inFile) > 0) {
        fwrite(buffer, 1, sizeof(buffer), outFile);
    }
    
    // Close the input and output files
    fclose(inFile);
    fclose(outFile);
}

// Function to read a digital watermark
char *readWatermark(char *filename, long int *fileSize) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return NULL;
    }
    
    // Read the message with the watermark and file size
    char message[1000];
    fread(message, sizeof(message), 1, file);
    
    // Get the size of the file from the message
    *fileSize = atol(strrchr(message, ' ') + 1);
    
    // Copy the watermark from the message
    char *watermark = malloc(strlen(message) - 1 - strlen(strrchr(message, ' ')));
    strncpy(watermark, message, strlen(message) - strlen(strrchr(message, ' ')));
    
    // Close the file
    fclose(file);
    
    return watermark;
}

// Main function
int main() {
    char *inputFile = "input.txt";
    char *outputFile = "output.txt";
    char *watermark = "This is a digital watermark!";
    
    createWatermark(inputFile, outputFile, watermark);
    
    long int fileSize;
    char *result = readWatermark(outputFile, &fileSize);
    
    if (result != NULL) {
        printf("Watermark found: %s\n", result);
        printf("File size: %ld bytes\n", fileSize);
        free(result);
    }
    
    return 0;
}