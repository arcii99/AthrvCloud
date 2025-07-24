//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 200
#define MAX_OUTPUT_SIZE 500

char* translate(char* input) {
    char* output = malloc(MAX_OUTPUT_SIZE);
    if (strcmp(input, "meow") == 0) {
        strcpy(output, "Hello");
    } else if (strcmp(input, "purr") == 0) {
        strcpy(output, "Thank you");
    } else if (strcmp(input, "hiss") == 0) {
        strcpy(output, "Warning");
    } else if (strcmp(input, "scratch") == 0) {
        strcpy(output, "I want food");
    } else if (strcmp(input, "nap") == 0) {
        strcpy(output, "I'm tired");
    } else {
        strcpy(output, "I don't understand");
    }
    return output;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter a phrase in C Cat language: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove newline character
    char* translated = translate(buffer);
    printf("Translation: %s\n", translated);
    free(translated);
    return 0;
}