//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1MB

void scanFile(char* filename) {
    FILE* file = fopen(filename, "rb"); // Open file in binary mode
    if (file == NULL) {
        printf("ERROR: Could not open file %s\n", filename);
        return;
    }
    
    unsigned char* buffer = (unsigned char*) calloc(MAX_FILE_SIZE, sizeof(unsigned char)); // Allocate memory for file buffer
    if (buffer == NULL) {
        printf("ERROR: Memory allocation failed for file buffer\n");
        fclose(file);
        return;
    }
    
    size_t bytesRead = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, file); // Read file into buffer
    fclose(file);
    
    if (bytesRead == 0) {
        printf("ERROR: Could not read file %s\n", filename);
        free(buffer);
        return;
    }
    
    int virusFound = 0;
    for (size_t i = 0; i < bytesRead - 3; i++) {
        if (memcmp(buffer + i, "virus", 5) == 0) { // Check if virus signature is found
            virusFound = 1;
            break;
        }
    }
    
    if (virusFound) {
        printf("WARNING: Virus detected in file %s\n", filename);
    } else {
        printf("File %s scanned successfully. No viruses found.\n", filename);
    }
    
    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR: No files to scan\n");
        return 1;
    }
    
    for (int i = 1; i < argc; i++) { // Scan each file provided as argument
        scanFile(argv[i]);
    }
    
    return 0;
}