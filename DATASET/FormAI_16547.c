//FormAI DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <string.h>

void main() {
    char input_str[1000];
    int word_count = 0;
    int char_count = 0;
    char last_char = ' ';
    char* newline = "\n";

    printf("Welcome to the Retro C Word Count Tool!\n");
    printf("---------------------------------------\n\n");
    printf("Type in your text (max 1000 chars):\n");

    // get user input
    fgets(input_str, 1000, stdin);

    // calculate word and char count
    for (int i = 0; i < strlen(input_str); i++) {
        if (input_str[i] == '\n') {
            continue;
        }
        if (input_str[i] != ' ' && last_char == ' ') {
            word_count++;
        }
        if (input_str[i] != ' ' && input_str[i] != '\n') {
            char_count++;
        }
        last_char = input_str[i];
    }

    // print results
    printf("\n");
    printf("Your text has %d words and %d characters (excluding spaces and newlines).\n", word_count, char_count);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Thanks for using the Retro C Word Count Tool!\n");
    printf("---------------------------------------\n");
}