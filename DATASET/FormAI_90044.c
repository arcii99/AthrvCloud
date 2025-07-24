//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 // define maximum length of file to be encrypted

void encryptFile(char filename[]) {
    FILE *fp = fopen(filename, "rb"); // open file for reading in binary mode

    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    // create new encrypted file
    char newFilename[strlen(filename) + 4]; // add 4 to accommodate ".enc" file extension
    strcpy(newFilename, filename);
    strcat(newFilename, ".enc");
    FILE *encFile = fopen(newFilename, "wb"); // open new file for writing in binary mode

    if (encFile == NULL) {
        printf("Failed to create encrypted file %s\n", newFilename);
        return;
    }

    // read input file in chunks and encrypt each chunk
    unsigned char buffer[MAX_LENGTH];
    int bytesRead;
    while ((bytesRead = fread(buffer, sizeof(unsigned char), MAX_LENGTH, fp)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= 0xFF; // XOR each byte with 11111111 to encrypt it
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, encFile); // write encrypted chunk to new file
    }

    fclose(fp);
    fclose(encFile);
    printf("File %s encrypted successfully!\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./encrypt [filename]\n");
        return 1;
    }

    encryptFile(argv[1]);

    return 0;
}