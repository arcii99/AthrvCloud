//FormAI DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY 0xFF

void encrypt(char *filename);
void decrypt(char *filename);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <filename> <mode>\n", argv[0]);
        printf("\twhere <filename> is the name of the file to be encrypted/decrypted\n");
        printf("\tand <mode> must be 'e' (encryption) or 'd' (decryption)\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    char *mode = argv[2];

    if(strcmp(mode, "e") == 0) {
        encrypt(filename);
    } else if(strcmp(mode, "d") == 0) {
        decrypt(filename);
    } else {
        printf("Invalid mode specified. Must be 'e' (encryption) or 'd' (decryption)\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void encrypt(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Error: file not found or could not be opened\n");
        exit(EXIT_FAILURE);
    }

    char *encrypted_filename = malloc(strlen(filename) + 5); // add ".enc" to end of filename
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");

    FILE *enc_fp = fopen(encrypted_filename, "wb");
    if(!enc_fp) {
        fclose(fp);
        free(encrypted_filename);
        printf("Error: could not create encrypted file\n");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];

    while(fread(buffer, 1, BUFFER_SIZE, fp)) {
        for(int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = buffer[i] ^ KEY; // apply XOR operation with key
        }
        fwrite(buffer, 1, BUFFER_SIZE, enc_fp);
    }

    fclose(fp);
    fclose(enc_fp);
    free(encrypted_filename);

    printf("File encrypted successfully!\n");
}

void decrypt(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Error: file not found or could not be opened\n");
        exit(EXIT_FAILURE);
    }

    char *decrypted_filename = malloc(strlen(filename) - 3); // remove ".enc" from end of filename
    strncpy(decrypted_filename, filename, strlen(filename) - 4);

    FILE *dec_fp = fopen(decrypted_filename, "wb");
    if(!dec_fp) {
        fclose(fp);
        free(decrypted_filename);
        printf("Error: could not create decrypted file\n");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];

    while(fread(buffer, 1, BUFFER_SIZE, fp)) {
        for(int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = buffer[i] ^ KEY; // apply XOR operation with key
        }
        fwrite(buffer, 1, BUFFER_SIZE, dec_fp);
    }

    fclose(fp);
    fclose(dec_fp);
    free(decrypted_filename);

    printf("File decrypted successfully!\n");
}