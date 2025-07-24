//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *file_path, char *key) {
    FILE *file_ptr = fopen(file_path, "rb+");
    if(file_ptr == NULL) {
        printf("Unable to open file\n");
        return;
    }

    // Determine file size
    fseek(file_ptr, 0L, SEEK_END);
    int file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Allocate memory for file content
    char *content = (char*) malloc(sizeof(char) * file_size);
    fread(content, sizeof(char), file_size, file_ptr);

    // Encrypt file content with XOR operation using provided key
    for(int i = 0; i < file_size; i++) {
        content[i] ^= key[i % strlen(key)];
    }

    // Write encrypted content back to file
    rewind(file_ptr);
    fwrite(content, sizeof(char), file_size, file_ptr);

    // Clean up
    free(content);
    fclose(file_ptr);
}

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Invalid arguments. Usage: ./encryptor <file_path> <key>\n");
        return 1;
    }

    char *file_path = argv[1];
    char *key = argv[2];

    encrypt(file_path, key);

    printf("File encryption complete!\n");

    return 0;
}