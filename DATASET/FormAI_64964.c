//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A unique compression algorithm - Time to have some fun!
char* compress(char* input) {
    int len = strlen(input);
    char* output = malloc(sizeof(char) * (len*2+1));

    int count = 1;
    char curr = input[0];
    int index = 0;

    for (int i = 1; i < len; i++) {
        if (input[i] != curr) {
            output[index++] = curr;
            output[index++] = '0' + count;
            count = 1;
            curr = input[i];
        } else {
            count++;
        }
    }

    output[index++] = curr;
    output[index++] = '0' + count;
    output[index] = '\0';

    return output;
}

int main() {
    printf("Welcome to the wackiest compression algorithm ever!\n");

    char input[500];

    printf("Enter your string to compress:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char* compressed = compress(input);

    printf("Your compressed string is:\n%s\n", compressed);

    free(compressed);

    printf("I hope you had as much fun as I did!\n");
    return 0;
}