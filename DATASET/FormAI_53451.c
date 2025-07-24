//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file); // getting file size
    rewind(file);

    // creating an encrypted file
    char* encrypted_file_name = malloc(strlen(file_name) + 8); // adding ".enc" extension
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".enc");
    
    FILE* encrypted_file = fopen(encrypted_file_name, "w");
    if(encrypted_file == NULL) {
        printf("Error creating encrypted file!\n");
        exit(1);
    }

    // encrypting the file
    int i;
    for(i = 0; i < file_size; i++) {
        char c = fgetc(file);
        c += 5; // shifting ASCII value by 5
        fputc(c, encrypted_file);
    }

    printf("%s has been encrypted successfully and saved as %s!\n", file_name, encrypted_file_name);

    fclose(file);
    fclose(encrypted_file);
    free(encrypted_file_name);
}

void decrypt(char* encrypted_file_name) {
    FILE* encrypted_file = fopen(encrypted_file_name, "r");
    if(encrypted_file == NULL) {
        printf("Error opening encrypted file!\n");
        exit(1);
    }

    fseek(encrypted_file, 0, SEEK_END);
    long file_size = ftell(encrypted_file); // getting file size
    rewind(encrypted_file);

    // creating a decrypted file
    char* decrypted_file_name = malloc(strlen(encrypted_file_name) - 3); // removing ".enc" extension
    strncpy(decrypted_file_name, encrypted_file_name, strlen(encrypted_file_name) - 4);
    
    FILE* decrypted_file = fopen(decrypted_file_name, "w");
    if(decrypted_file == NULL) {
        printf("Error creating decrypted file!\n");
        exit(1);
    }

    // decrypting the file
    int i;
    for(i = 0; i < file_size; i++) {
        char c = fgetc(encrypted_file);
        c -= 5; // shifting ASCII value back by 5
        fputc(c, decrypted_file);
    }

    printf("%s has been decrypted successfully and saved as %s!\n", encrypted_file_name, decrypted_file_name);

    fclose(encrypted_file);
    fclose(decrypted_file);
    free(decrypted_file_name);
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: ./file_encryptor <encrypt/decrypt> <file_name>\n");
        exit(1);
    }

    char* mode = argv[1];
    char* file_name = argv[2];

    if(strcmp(mode, "encrypt") == 0) {
        encrypt(file_name);
    }
    else if(strcmp(mode, "decrypt") == 0) {
        decrypt(file_name);
    }
    else {
        printf("Mode must be either 'encrypt' or 'decrypt'.\n");
        exit(1);
    }

    return 0;
}