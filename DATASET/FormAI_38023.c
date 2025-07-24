//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char *fileName);

int main(int argc, char *argv[]) {
    if(argc == 2){
        char *fileName = argv[1];
        encryptFile(fileName);
        printf("Your file has been encrypted successfully!\n");
    } else {
        printf("Sorry, I can only encrypt one file at a time.\n");
        exit(1);
    }
    return 0;
}

void encryptFile(char *fileName) {
    char *newFileName = strcat(fileName, ".encrypted");
    FILE *originalFile = fopen(fileName, "rb");
    FILE *encryptedFile = fopen(newFileName, "wb");

    unsigned char key = 'S';

    if(originalFile == NULL){
        printf("Error: File not found\n");
        exit(1);
    }

    fseek(originalFile, 0L, SEEK_END);
    int fileSize = ftell(originalFile);
    rewind(originalFile);

    unsigned char *buffer = (unsigned char *)malloc(fileSize);

    fread(buffer, sizeof(unsigned char), fileSize, originalFile);

    for(int i = 0; i < fileSize; i++){
        buffer[i] ^= key;
    }

    fwrite(buffer, sizeof(unsigned char), fileSize, encryptedFile);
    fclose(originalFile);
    fclose(encryptedFile);
    free(buffer);
}