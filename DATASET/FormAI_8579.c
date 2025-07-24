//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file_name, char *pass_key);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s [file_name] [pass_key]\n", argv[0]);
        return EXIT_FAILURE;
    }
    encrypt(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void encrypt(char *file_name, char *pass_key) {
    FILE *fptr; // file pointer
    fptr = fopen(file_name, "rb+");
    int ch;
    long i = 0;
    while((ch = fgetc(fptr)) != EOF) {
        // encryption logic
        ch = ch ^ pass_key[i];
        i++;
        if(pass_key[i] == '\0') {
            i = 0;
        }
        fseek(fptr, -1, SEEK_CUR); // move the file pointer one position back
        fputc(ch, fptr); // write the encrypted data to the file
    }
    printf("Encryption completed successfully!\n");
    fclose(fptr); // close the file
}