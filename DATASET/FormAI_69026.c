//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

void encode(char *input, char *output) {
    char encoded[MAX_OUTPUT_SIZE] = "";
    int count = 1;
    char current = input[0];
    int i;

    for (i = 1; input[i] != '\0'; i++) {
        if (input[i] == current) {
            count++;
        } else {
            sprintf(encoded + strlen(encoded), "%d%c", count, current);
            count = 1;
            current = input[i];
        }
    }

    sprintf(encoded + strlen(encoded), "%d%c", count, current);

    strcpy(output, encoded);
}

void decode(char *input, char *output) {
    char decoded[MAX_INPUT_SIZE] = "";
    int count = 0;
    char current;
    int i, j;

    for (i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
        } else {
            current = input[i];
            for (j = 0; j < count; j++) {
                sprintf(decoded + strlen(decoded), "%c", current);
            }
            count = 0;
        }
    }

    strcpy(output, decoded);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    char decoded[MAX_INPUT_SIZE];

    printf("Enter a string to compress: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;

    encode(input, output);

    printf("The compressed string is: %s\n", output);

    decode(output, decoded);

    printf("The decompressed string is: %s\n", decoded);

    return 0;
}