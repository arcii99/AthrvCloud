//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key to encrypt the file
#define KEY 0x1A

// Define the maximum file size to encrypt
#define MAX_FILE_SIZE 1024

/**
 * Function to encrypt a given file
 * @param  inputFile  The input file to encrypt
 * @param  outputFile The output file to write the encrypted data to
 * @return            0 if encryption is successful, -1 otherwise
 */
int encryptFile(const char* inputFile, const char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    if (!input) {
        perror("Unable to open input file");
        return -1;
    }
    
    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytesRead = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, input);
    if (bytesRead == 0) {
        perror("Unable to read input file");
        fclose(input);
        return -1;
    }
    
    // Encrypt the data in buffer
    for (int i = 0; i < bytesRead; i++) {
        buffer[i] = ~buffer[i] ^ KEY;
    }
    
    fclose(input);
    
    FILE* output = fopen(outputFile, "wb");
    if (!output) {
        perror("Unable to open output file");
        return -1;
    }
    
    size_t bytesWritten = fwrite(buffer, sizeof(unsigned char), bytesRead, output);
    if (bytesWritten != bytesRead) {
        perror("Unable to write to output file");
        fclose(output);
        return -1;
    }
    
    fclose(output);
    
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return -1;
    }
    
    int result = encryptFile(argv[1], argv[2]);
    if (result != 0) {
        fprintf(stderr, "File encryption failed!\n");
        return -1;
    }
    
    printf("File encrypted successfully!\n");
    
    return 0;
}