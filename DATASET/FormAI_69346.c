//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char c_cat_lang[20];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a phrase in C Cat Language:\n");
    scanf("%s", c_cat_lang);
    strcat(c_cat_lang, " meow");
    printf("Translation: %s\n", c_cat_lang);
    return 0;
}