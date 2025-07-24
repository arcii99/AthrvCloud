//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
/* Cat Language Translator */

#include <stdio.h>
#include <string.h>

int main() {

    printf("\n");
    printf("Welcome to the Cat Language Translator!\n");
    printf("\n");

    /* Input cat word */
    char cat_word[50];
    printf("Enter a word in Cat language: ");
    scanf("%s", cat_word);
    printf("\n");

    /* Translate cat word to English */
    if(strcmp(cat_word, "meow") == 0) {
        printf("Translation: Hello!\n");
    }
    else if(strcmp(cat_word, "purr") == 0) {
        printf("Translation: Thank you!\n");
    }
    else if(strcmp(cat_word, "hiss") == 0) {
        printf("Translation: I'm scared!\n");
    }
    else if(strcmp(cat_word, "sniff") == 0) {
        printf("Translation: What's that smell?\n");
    }
    else if(strcmp(cat_word, "lick") == 0) {
        printf("Translation: Yummy!\n");
    }
    else if(strcmp(cat_word, "scratch") == 0) {
        printf("Translation: I'm itchy!\n");
    }
    else if(strcmp(cat_word, "sleep") == 0) {
        printf("Translation: Zzz...\n");
    }
    else {
        printf("Translation: I don't understand!\n");
    }

    printf("\n");
    printf("Thank you for using the Cat Language Translator!\n");
    printf("\n");

    return 0;
}