//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x5F

void encrypt(char *filename) {
    FILE *fp;
    int ch;
    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("\nUnable to open the file %s.\n", filename);
        return;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    for (long i = 0; i < file_size; i++) {
        ch = getc(fp) ^ ENCRYPT_KEY;
        fseek(fp, i, SEEK_SET);
        putc(ch, fp);
    }
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    encrypt(filename);
    printf("The file %s has been encrypted.\n", filename);
    return 0;
}