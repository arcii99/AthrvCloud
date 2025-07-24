//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void encrypt(char* filename, int key) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    char buffer[MAX_LENGTH];
    char ch;
    int len, i;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n' || ch == '\r') {
            continue;
        }
        buffer[len++] = ch;
    }

    fseek(file, 0, SEEK_SET);
    for (i = 0; i < len; i++) {
        printf("%c", buffer[i] ^ key);
        fprintf(file, "%c", buffer[i] ^ key);
    }

    fclose(file);
}

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        printf("Usage: %s [filename] [key]\n", argv[0]);
        return 0;
    }

    char* filename = argv[1];
    int key = atoi(argv[2]);

    encrypt(filename, key);

    return 0;
}