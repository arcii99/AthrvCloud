//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_KEY_LEN 100

void encrypt(char *filename, char *key) {
    FILE *fp;
    char ch;
    int keylen = strlen(key);
    int i = 0;

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        perror("Error in opening file");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        fpos_t position;
        fgetpos(fp, &position);

        fseek(fp, i % keylen, SEEK_SET);
        fputc(ch ^ key[i % keylen], fp);

        fsetpos(fp, &position);
        i++;
    }

    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(filename, key);

    printf("File encrypted successfully!");

    return 0;
}