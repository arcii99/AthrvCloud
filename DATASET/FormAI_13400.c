//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

char *compress(char *string) {
    int count = 1, index = 0;
    char *compressedString = (char*)calloc(MAX_STRING_LENGTH, sizeof(char));
    if (compressedString == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == string[i+1]) {
            count++;
        }
        else {
            compressedString[index++] = string[i];
            compressedString[index++] = '0' + count;
            count = 1;
        }
    }
    compressedString[index] = '\0';
    return compressedString;
}

int main() {
    char string[MAX_STRING_LENGTH], *compressedString;
    printf("Enter a string to compress: ");
    scanf("%[^\n]", string);
    compressedString = compress(string);
    printf("Original string: %s\n", string);
    printf("Compressed string: %s\n", compressedString);
    free(compressedString);
    return 0;
}