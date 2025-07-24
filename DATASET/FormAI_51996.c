//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
    char cat_sentence[100];
    int choice;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence in C Cat Language:\n");
    fgets(cat_sentence, 100, stdin);

    printf("Choose an option:\n");
    printf("1. Translate to English\n");
    printf("2. Translate to Meow\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Translation to English:\n");
        if (strcmp(cat_sentence, "meow") == 0) {
            printf("Hello\n");
        } else if (strcmp(cat_sentence, "meow meow") == 0) {
            printf("How are you?\n");
        } else if (strcmp(cat_sentence, "meow meow meow") == 0) {
            printf("I am doing well, thank you\n");
        } else {
            printf("Sorry, I do not understand the sentence\n");
        }
    } else if (choice == 2) {
        printf("Translation to Meow:\n");
        if (strcmp(cat_sentence, "Hello\n") == 0) {
            printf("meow\n");
        } else if (strcmp(cat_sentence, "How are you?\n") == 0) {
            printf("meow meow\n");
        } else if (strcmp(cat_sentence, "I am doing well, thank you\n") == 0) {
            printf("meow meow meow\n");
        } else {
            printf("Sorry, I do not understand the sentence\n");
        }
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}