//FormAI DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

void xor_encrypt(char* s, int key) {
    for (int i = 0; i < strlen(s); ++i) {
        s[i] ^= key;
    }
}

void encrypt_file(const char* filename, int key) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char buffer[MAX_STRING_SIZE];
    while(fgets(buffer, MAX_STRING_SIZE, file) != NULL) {
        xor_encrypt(buffer, key);
        fseek(file, -strlen(buffer), SEEK_CUR);
        fwrite(buffer, 1, strlen(buffer), file);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./encrypt <filename> <key>\n");
        return 0;
    }
    const char* filename = argv[1];
    int key = atoi(argv[2]);

    encrypt_file(filename, key);

    printf("Encrypted file '%s' with key %d\n", filename, key);

    return 0;
}