//FormAI DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename, char key[]);
void decrypt(char *filename, char key[]);

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <filename> <key> <flag (e/d)>\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];
    char *key = argv[2];
    char flag = argv[3][0];

    if(flag == 'e') {
        encrypt(filename, key);
        printf("File encrypted successfully!\n");
    }
    else if(flag == 'd') {
        decrypt(filename, key);
        printf("File decrypted successfully!\n");
    }
    else {
        printf("Unknown flag '%c'\n", flag);
    }

    return 0;
}

void encrypt(char *filename, char key[]) {
    FILE *fp = fopen(filename, "r+");
    char c;

    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        fseek(fp, i, SEEK_SET);
        fputc(c ^ key[i % strlen(key)], fp);
        i++;
    }

    fclose(fp);
}

void decrypt(char *filename, char key[]) {
    encrypt(filename, key);
}