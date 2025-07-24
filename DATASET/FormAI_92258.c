//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Welcome to the C File Encryptor!\n");
    printf("Please enter the name of the file you want to encrypt: ");
    char filename[100];
    scanf("%s", filename);
    printf("Enter a secret key for encryption: ");
    char key[100];
    scanf("%s", key);
    printf("Encrypting file...\n");
    FILE* input_file = fopen(filename, "rb");
    fseek(input_file, 0, SEEK_END);
    long int size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    char* buffer = (char*)malloc(size);
    fread(buffer, size, 1, input_file);
    fclose(input_file);
    for(int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }
    char encrypted_filename[100];
    snprintf(encrypted_filename, 100, "%s_encrypted", filename);
    FILE* output_file = fopen(encrypted_filename, "wb");
    fwrite(buffer, size, 1, output_file);
    fclose(output_file);
    printf("File successfully encrypted and saved as %s\n", encrypted_filename);
    free(buffer);
    return 0;
}