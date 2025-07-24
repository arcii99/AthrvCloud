//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* input) {
    int len = strlen(input);
    char* output = (char*) malloc(sizeof(char) * (MAX_SIZE + 1));
    int outLen = 0;
    int count = 1;

    for (int i = 0; i < len; i++) {
        if (input[i] != input[i+1] || count == 9) {
            output[outLen++] = input[i];
            output[outLen++] = '0' + count;
            count = 1;
        } else {
            count++;
        }
    }

    output[outLen] = '\0';
    return output;
}

int main() {
    char* input = "aaabbbbcccccddddee";
    char* output = compress(input);

    printf("Input: %s\nOutput: %s\n", input, output);

    free(output);
    return 0;
}