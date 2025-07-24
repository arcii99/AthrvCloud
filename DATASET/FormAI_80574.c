//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void handleError(int errorCode) {
    char* errorMessage;
    switch(errorCode) {
        case 1:
            errorMessage = "Error code 1: File not found.";
            break;
        case 2:
            errorMessage = "Error code 2: Out of memory.";
            break;
        default:
            errorMessage = "Unknown error.";
            break;
    }
    printf("%s\n", errorMessage);
    exit(errorCode);
}

int main() {
    FILE* fp;
    char* fileName = "nonexistentFile.txt";
    char* buffer;

    // Open the file for reading
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        handleError(1);
    }

    // Read the contents of the file into a char buffer
    buffer = (char*) malloc(sizeof(char) * 100);
    if (buffer == NULL) {
        handleError(2);
    }
    fgets(buffer, 100, fp);

    // Close the file and free the buffer memory
    fclose(fp);
    free(buffer);
    
    return 0;
}