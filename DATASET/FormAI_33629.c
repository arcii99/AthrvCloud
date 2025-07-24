//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char catLang[100];

    printf("Welcome to the Cat Language Translator Program! Meow!\n\n");
    printf("Please enter a phrase in Cat Language:\n");

    // Read input
    fgets(catLang, sizeof(catLang), stdin);

    // Replace "meow" with "happy"
    for (int i = 0; i < strlen(catLang); i++) {
        if (catLang[i] == 'm' && catLang[i+1] == 'e' && catLang[i+2] == 'o' && catLang[i+3] == 'w') {
            catLang[i] = 'h';
            catLang[i+1] = 'a';
            catLang[i+2] = 'p';
            catLang[i+3] = 'p';
            catLang[i+4] = 'y';
        }
    }

    printf("\nTranslation Result:\n%s\n\n", catLang);
    printf("Thank you for using the Cat Language Translator Program! Purr!\n");

    return 0;
}