//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to be encrypted

void encryptFile(char filename[], char key[]);
char* getEncryptedFileName(char filename[]);

int main(void) {
    char filename[100], key[100];
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encryptFile(filename, key);
    return 0;
}

void encryptFile(char filename[], char key[]) {
    FILE* fp, *fp_enc;
    char ch;
    char destination[100];
    int i = 0;
    strcpy(destination, getEncryptedFileName(filename));
    fp = fopen(filename, "r");
    fp_enc = fopen(destination, "w");
    if(fp == NULL) {
        printf("File does not exist!\n");
        exit(EXIT_FAILURE);
    }
    while((ch = fgetc(fp)) != EOF) {
        ch = (ch + key[i++ % strlen(key)]) % 256;
        fputc(ch, fp_enc);
    }
    fclose(fp);
    fclose(fp_enc);
    printf("File encrypted successfully!\n");
}

char* getEncryptedFileName(char filename[]) {
    char* ext = ".enc";
    char* result = malloc(strlen(filename) + strlen(ext) + 1);
    strcpy(result, filename);
    strcat(result, ext);
    return result;
}