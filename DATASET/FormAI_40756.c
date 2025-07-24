//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include<stdio.h>
#include<string.h>

void cat_to_english(char* cat_lang);

int main() {

    printf("Welcome to the C Cat Language Translator! \n");
    printf("Please enter your message in Cat Language: \n");

    char cat_words[100];
    fgets(cat_words, 100, stdin);

    // Remove new line character added by fgets
    cat_words[strcspn(cat_words, "\n")] = 0;

    // Translate cat language to English
    cat_to_english(cat_words);

    return 0;
}

void cat_to_english(char* cat_lang) {
    if(strcmp(cat_lang, "mew") == 0) {
        printf("Hello\n");
    }
    else if(strcmp(cat_lang, "purr") == 0) {
        printf("Thank you\n");
    }
    else if(strcmp(cat_lang, "hiss") == 0) {
        printf("Sorry\n");
    }
    else if(strcmp(cat_lang, "meow") == 0) {
        printf("I am hungry\n");
    }
    else if(strcmp(cat_lang, "scratch") == 0) {
        printf("I want to play\n");
    }
    else {
        printf("I do not understand\n");
    }
}