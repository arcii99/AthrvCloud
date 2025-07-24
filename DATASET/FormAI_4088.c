//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to convert input string to C Cat Language
char* encode(char input[]) {
    int i, j;
    char* output = malloc(2 * strlen(input) * sizeof(char));
    for(i = 0, j = 0; i < strlen(input); i++, j += 2) {
        output[j] = input[i];
        output[j+1] = 'p';
    }
    output[j] = '\0';
    return output;
}

// Function to convert C Cat Language to English
char* decode(char input[]) {
    int i, j;
    char* output = malloc(strlen(input) / 2 * sizeof(char));
    for(i = 0, j = 0; i < strlen(input); i += 2, j++) {
        output[j] = input[i];
    }
    output[j] = '\0';
    return output;
}

int main() {
    char input[100];
    printf("Enter text to encode in C Cat Language: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input
    char* encoded = encode(input);

    // Output encoded C Cat Language
    printf("Encoded in C Cat Language: %s\n", encoded);

    // Decode and output original input
    char* decoded = decode(encoded);
    printf("Decoded: %s\n", decoded);

    free(encoded);
    free(decoded);
    return 0;
}