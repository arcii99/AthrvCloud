//FormAI DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename, char *key) {
    FILE *fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Could not open file!\n");
        exit(1);
    }

    char ch;
    int keylen = strlen(key);
    int i = 0;

    while (fread(&ch, sizeof(char), 1, fp) == 1) {
        ch ^= key[i];
        fwrite(&ch, sizeof(char), 1, fp);

        i++;
        if (i == keylen) {
            i = 0;
        }
    }

    fclose(fp);
}

int main() {
    char filename[100];
    char key[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(filename, key);

    printf("Encryption Successful!\n");

    return 0;
}