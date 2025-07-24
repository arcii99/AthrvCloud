//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

void ccat_to_english(char[]);

int main() {
    char phrase[100];

    printf("Enter a phrase in C Cat Language: ");
    fgets(phrase, 100, stdin);

    ccat_to_english(phrase);

    return 0;
}

void ccat_to_english(char phrase[]) {
    char* word;
    const char delimiter[2] = " ";
    word = strtok(phrase, delimiter);

    while (word != NULL) {
        if (strcmp(word, "meow") == 0) {
            printf("I ");
        }
        else if (strcmp(word, "purr") == 0) {
            printf("like ");
        }
        else if (strcmp(word, "hiss") == 0) {
            printf("dislike ");
        }
        else if (strcmp(word, "mew") == 0) {
            printf("am ");
        }
        else if (strcmp(word, "paw") == 0) {
            printf("using ");
        }
        else if (strcmp(word, "tail") == 0) {
            printf("to ");
        }
        else if (strcmp(word, "feline") == 0) {
            printf("cat ");
        }
        else if (strcmp(word, "kitten") == 0) {
            printf("baby cat ");
        }
        else {
            printf("%s ", word);
        }

        word = strtok(NULL, delimiter);
    }
}