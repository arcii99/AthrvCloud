//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the input string
#define MAX_SIZE 100

int main() {
    char cat_input[MAX_SIZE];
    char translated_output[MAX_SIZE];

    printf("Enter your input in C Cat Language: ");
    fgets(cat_input, MAX_SIZE, stdin);

    int len = strlen(cat_input) - 1;

    // Translate the input string
    for (int i = 0; i < len; i++) {
        char current_char = cat_input[i];

        if (current_char == 'm') {
            translated_output[i] = 'c';
        } else if (current_char == 'e') {
            translated_output[i] = 'a';
        } else if (current_char == 'o') {
            translated_output[i] = 't';
        } else if (current_char == 'w') {
            translated_output[i] = 'h';
        } else if (current_char == 'w' && cat_input[i+1] == 'w') {
            translated_output[i] = ' ';
            translated_output[i+1] = ' ';
            i++;
        } else {
            translated_output[i] = current_char;
        }
    }

    // Display the translated output
    printf("\nTranslated Output: %s\n", translated_output);

    return 0;
}