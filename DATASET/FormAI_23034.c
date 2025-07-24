//FormAI DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 10000;

void encrypt(char *filename, char *password) {
    char data[MAX_SIZE];
    FILE *file;
    int i = 0;

    file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("\nFailed to open file\n");
        return;
    }

    while (!feof(file)) {
        data[i] = fgetc(file);
        i++;
    }
    data[i-1] = '\0';

    for (i = 0; i < strlen(data); i++) {
        data[i] = data[i] ^ password[(i % strlen(password))];
    }

    rewind(file);
    fputs(data, file);
    fclose(file);
}

int main() {
    char filename[MAX_SIZE], password[MAX_SIZE];

    printf("Enter the filename to encrypt: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter password to encrypt: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    encrypt(filename, password);

    printf("\nEncryption complete.\n");

    return 0;
}