//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file, char *key) {
    FILE *fp = fopen(file, "rb");
    if (!fp) {
        printf("Error: could not open file %s.\n", file);
        exit(1);
    }
    int keylen = strlen(key);
    int i = 0;
    char byte, k;
    while (fread(&byte, 1, 1, fp) == 1) {
        k = key[i++ % keylen];
        byte ^= k;
        printf("%c", byte);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s filename key\n", argv[0]);
        return 1;
    }
    char *file = argv[1];
    char *key = argv[2];
    encrypt(file, key);
    return 0;
}