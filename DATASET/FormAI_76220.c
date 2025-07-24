//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 256
#define MAX_CHAR_VAL 127
#define MIN_CHAR_VAL -128

void paranoid_compress(char *str, unsigned char **compressedStr, size_t *compressedSize);

int main() {
    char str[MAX_STR_SIZE];
    printf("Enter a string to compress: ");
    fgets(str, MAX_STR_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input
    printf("Compressing: %s\n", str);

    unsigned char *compressedStr;
    size_t compressedSize;

    paranoid_compress(str, &compressedStr, &compressedSize);

    printf("Compressed size: %lu bytes\n", compressedSize);
    printf("Compressed string: ");
    for (size_t i = 0; i < compressedSize; i++) {
        printf("%02x ", compressedStr[i]);
    }
    printf("\n");

    free(compressedStr);

    return 0;
}

void paranoid_compress(char *str, unsigned char **compressedStr, size_t *compressedSize) {
    size_t strLen = strlen(str);
    if (strLen == 0){
        printf("Error: Cannot compress empty string.\n");
        exit(1);
    }

    int offset = 0;
    char curChar = str[offset];
    signed char prevCharDiff = 0;
    size_t compressedBytes = 0;

    *compressedStr = (unsigned char*) malloc(strLen * sizeof(signed char) * 2);
    if (*compressedStr == NULL) {
        printf("Error: Unable to allocate memory for compressed string.\n");
        exit(1);
    }

    while (curChar != '\0') {
        signed char charDiff = curChar - prevCharDiff;
        if (charDiff > MAX_CHAR_VAL || charDiff < MIN_CHAR_VAL) {
            // Need to split current diff into multiple bytes
            do {
                printf("Warning: Character difference too large. Splitting into multiple bytes.\n");
                (*compressedStr)[compressedBytes++] = (unsigned char) ((charDiff & 0x7f) | 0x80);
                charDiff >>= 7;
            } while (charDiff != 0);
        }

        prevCharDiff = curChar;
        offset++;
        curChar = str[offset];
    }

    *compressedSize = compressedBytes;
}