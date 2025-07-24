//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define the alien language mapping as a struct
typedef struct {
    char alien_char;
    char english_char;
} AlienMapping;

// Define the translation table as an array of AlienMappings
AlienMapping translation_table[] = {
    {'a', 'z'},
    {'b', 'y'},
    {'c', 'x'},
    {'d', 'w'},
    {'e', 'v'},
    {'f', 'u'},
    {'g', 't'},
    {'h', 's'},
    {'i', 'r'},
    {'j', 'q'},
    {'k', 'p'},
    {'l', 'o'},
    {'m', 'n'},
    {'n', 'm'},
    {'o', 'l'},
    {'p', 'k'},
    {'q', 'j'},
    {'r', 'i'},
    {'s', 'h'},
    {'t', 'g'},
    {'u', 'f'},
    {'v', 'e'},
    {'w', 'd'},
    {'x', 'c'},
    {'y', 'b'},
    {'z', 'a'}
};

// Define a function to translate a single character
char translate_char(char c) {
    for (int i = 0; i < sizeof(translation_table) / sizeof(AlienMapping); i++) {
        if (translation_table[i].alien_char == c) {
            return translation_table[i].english_char;
        }
    }
    return c;
}

// Define a function to translate a full string
void translate_string(char* input, char* output) {
    int input_len = strlen(input);
    for (int i = 0; i < input_len; i++) {
        output[i] = translate_char(input[i]);
    }
    output[input_len] = '\0';
}

int main() {
    char input[100];
    char output[100];

    printf("Enter an alien message: ");
    fgets(input, 100, stdin);

    translate_string(input, output);

    printf("English message: %s\n", output);

    return 0;
}