//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// This is an example of a compression algorithm that uses the concept of run-length encoding
// It takes in a string and returns a compressed version of the same string
char* compress(char* input) {
    char* output = malloc(sizeof(char) * 2 * strlen(input));
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        int count = 1;
        output[j] = input[i];
        while (input[i] == input[i+1]) {
            count++;
            i++;
        }
        i++;
        if (count == 1) {
            j++;
            continue;
        }
        char* count_str = malloc(sizeof(char) * 10);
        sprintf(count_str, "%d", count);
        int k = 0;
        while (count_str[k] != '\0') {
            output[++j] = count_str[k];
            k++;
        }
        free(count_str);
        j++;
    }
    output[j] = '\0';
    return output;
}

int main() {
    char input[100];
    printf("Enter a string to compress: ");
    fgets(input, 100, stdin);
    char* compressed = compress(input);
    printf("The compressed string is: %s\n", compressed);
    free(compressed);
    return 0;
}