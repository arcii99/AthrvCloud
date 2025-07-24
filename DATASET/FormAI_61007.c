//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {

    char input[1000];
    char output[1000];

    // Greetings in C Cat Language
    char* cat_greetings[] = {"Meow!", "Purr!", "Hiss!", "Mrrow!", "Rawr!"};
    int num_greetings = sizeof(cat_greetings) / sizeof(cat_greetings[0]);

    printf("Welcome to the C Cat Language Translator!\n");

    // Get user input
    printf("Enter a phrase in C Cat Language:\n");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    // Translate input to English
    int i;
    char temp[100];
    char* word = strtok(input, " ");
    while (word != NULL) {
        for (i = 0; i < num_greetings; i++) {
            if (strcmp(word, cat_greetings[i]) == 0) {
                sprintf(temp, "%d", i);
                strcat(output, temp);
                strcat(output, " ");
                break;
            }
        }
        if (i == num_greetings) {
            strcat(output, word);
            strcat(output, " ");
        }
        word = strtok(NULL, " ");
    }

    // Output translated string
    printf("Translated phrase: %s\n", output);

    return 0;
}