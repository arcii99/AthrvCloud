//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {

    char input[MAX_SIZE + 1];

    // read input string
    printf("Enter string: ");
    fgets(input, MAX_SIZE, stdin);

    // remove any non-alphabetic characters from input string
    int i = 0;
    int j = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            input[j++] = toupper(input[i]);
        }
        i++;
    }
    input[j] = '\0';

    // initialize arrays for encoding and decoding
    char encode[MAX_SIZE + 1];
    int indices[MAX_SIZE];
    int count = 0;
    int index = 0;
    char current = input[0];

    // perform run-length encoding
    for (i = 1; input[i] != '\0'; i++) {
        if (input[i] == current) {
            count++;
        } else {
            encode[index++] = current;
            encode[index++] = count + '0';
            indices[index / 2 - 1] = i - count;
            count = 1;
            current = input[i];
        }
    }
    encode[index++] = current;
    encode[index++] = count + '0';
    indices[index / 2 - 1] = i - count;

    // print encoded string and indices
    printf("Encoded string: %s\n", encode);
    printf("Indices: ");
    for (i = 0; i < index / 2; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    // perform run-length decoding
    char decode[MAX_SIZE + 1];
    index = 0;
    for (i = 0; encode[i] != '\0'; i += 2) {
        current = encode[i];
        count = encode[i + 1] - '0';
        for (j = 0; j < count; j++) {
            decode[index++] = current;
        }
    }
    decode[index] = '\0';

    // print decoded string
    printf("Decoded string: %s\n", decode);

    return 0;
}