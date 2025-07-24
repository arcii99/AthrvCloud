//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

void meow(char *cat_lang) {
    if (strcmp(cat_lang, "meow") == 0) {
        printf("Meow meow!\n");
    } else if (strcmp(cat_lang, "purr") == 0) {
        printf("Purr purr...\n");
    } else if (strcmp(cat_lang, "hiss") == 0) {
        printf("Hiss hiss!\n");
    } else if (strcmp(cat_lang, "yawn") == 0) {
        printf("Yawn...\n");
    } else {
        printf("Unrecognized cat language.\n");
    }
}

int main() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a cat sound: ");

    char input[50];
    scanf("%s", input);

    meow(input);
    
    return 0;
}