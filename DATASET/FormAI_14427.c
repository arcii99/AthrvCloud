//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>

int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a sentence in Cat Language: ");

    char sentence[100];
    fgets(sentence, 100, stdin); // read user input

    printf("Translating...\n");

    // loop through each character in the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == 'm') {
            printf("Meow ");
        } else if (sentence[i] == 'p') {
            printf("Purr ");
        } else if (sentence[i] == 'h') {
            printf("Hiss ");
        } else if (sentence[i] == 'e') {
            printf("Meow ");
        } else if (sentence[i] == 'o') {
            printf("Purr ");
        } else if (sentence[i] == 'w') {
            printf("Hiss ");
        } else {
            printf("%c", sentence[i]);
        }
    }

    return 0;
}