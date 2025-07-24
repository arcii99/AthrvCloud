//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[] = "aabbbcccddeeeeeefffffgggggg";
    int length = strlen(string);

    char compressed[length];
    compressed[0] = string[0];
    int compressed_index = 0;

    for (int i = 0, j = 1; i < length; i++, j++) {
        if (string[i] == string[j]) {
            int count = 1;
            while (string[i] == string[j]) {
                count++;
                j++;
            }
            compressed[compressed_index++] = count + '0';
            compressed[compressed_index++] = string[i];
            i = j - 1;
        } else {
            compressed[compressed_index] = string[j];
            compressed_index++;
        }
    }

    printf("Original String: %s\n", string);
    printf("Compressed String: %s\n", compressed);

    return 0;
}