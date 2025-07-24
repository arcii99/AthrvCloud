//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 255

// function to compress the given text
void compress(char *text) {
    int count = 1;
    int index = 0;
    char compressed[MAX_SIZE];

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == text[i+1]) {
            count++;
        } else {
            compressed[index] = text[i];
            compressed[index+1] = count + '0';
            index += 2;
            count = 1;
        }
    }

    compressed[index] = '\0';

    printf("Original Text: %s\n", text);
    printf("Compressed Text: %s\n", compressed);
}

int main() {
    char text[MAX_SIZE];

    printf("Enter a string to compress: ");
    scanf("%s", text);

    compress(text);

    return 0;
}