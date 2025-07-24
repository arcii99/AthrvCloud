//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* input) {
    int len = strlen(input);
    char* output = (char*) malloc (len * sizeof(char));
    memset(output, 0, len);
    int count = 1;
    char current = input[0];
    int k = 0;
    for (int i = 1; i < len; i++) {
        if (input[i] == current) {
            count++;
        } else {
            output[k++] = current;
            output[k++] = count + '0';
            current = input[i];
            count = 1;
        }
    }
    output[k++] = current;
    output[k++] = count + '0';
    output[k++] = '\0';
    return output;
}

int main() {
    char* input = "aabbccaaa";
    char* compressed = compress(input);
    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    free(compressed);
    return 0;
}