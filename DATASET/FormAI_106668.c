//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

// function to translate C Cat language to English
void translate(char* ccat_word) {

    // check if word is valid in C Cat language
    if (strstr(ccat_word, "meow") == NULL) {
        printf("%s", ccat_word);
        return;
    }

    // translate C Cat word to English
    if (strcmp(ccat_word, "meow") == 0) {
        printf("hello");
    } else if (strcmp(ccat_word, "meowmeow") == 0) {
        printf("goodbye");
    } else if (strcmp(ccat_word, "meowmeowmeow") == 0) {
        printf("thank you");
    } else if (strcmp(ccat_word, "meowmeowmeowmeow") == 0) {
        printf("please");
    } else {
        printf("%s", ccat_word);
    }
}

int main() {
    char input[100];

    printf("Enter a sentence in C Cat language:\n");
    fgets(input, 100, stdin); // read user input

    char* token = strtok(input, " "); // split input sentence into words

    while (token != NULL) {
        translate(token); // translate each word from C Cat to English
        printf(" "); // add a space after each word
        token = strtok(NULL, " "); // move to next word
    }

    return 0;
}