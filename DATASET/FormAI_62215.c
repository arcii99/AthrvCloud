//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char* compress(char* input) {
    int count = 0;
    char current_char = input[0];
    char* output = malloc(MAX_LENGTH * sizeof(char));
    int i;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == current_char) {
            count++;
        }
        else {
            sprintf(output, "%s%c%d", output, current_char, count);
            count = 1;
            current_char = input[i];
        }
    }

    sprintf(output, "%s%c%d", output, current_char, count);

    return output;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    char* compressed = compress(input);
    
    printf("Compressed string: %s\n", compressed);

    free(compressed);

    return 0;
}