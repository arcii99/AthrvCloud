//FormAI DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB

void encryptFile(char* filePath, char* key){
    FILE *file = fopen(filePath, "rb+");
    if(file == NULL){
        printf("Error opening file.\n");
        return;
    }

    char buffer[MAX_FILE_SIZE];
    int bytesRead = 0;
    while((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0){
        for(int i = 0; i < bytesRead; i++){
            buffer[i] = buffer[i] ^ key[(i % strlen(key))];
        }
        fseek(file, -bytesRead, SEEK_CUR);
        fwrite(buffer, 1, bytesRead, file);
        fflush(file);
    }
    fclose(file);
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage: file-encryptor <file-path> <encryption-key>\n");
        return 1;
    }
    encryptFile(argv[1], argv[2]);
    printf("File encryption complete!\n");
    return 0;
}