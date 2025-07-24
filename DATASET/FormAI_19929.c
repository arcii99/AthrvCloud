//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    char ccat[100];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a C Cat sentence to translate:\n");
    fgets(ccat, 100, stdin);
    ccat[strcspn(ccat, "\n")] = '\0'; // remove newline character
   
    printf("\nTranslation: ");

    // Translate specific C Cat words
    if (strcmp(ccat, "meow") == 0) {
        printf("Hello!\n");
    } else if (strcmp(ccat, "hiss") == 0) {
        printf("Goodbye!\n");
    } else if (strstr(ccat, " scratch ") != NULL) {
        printf("Can you please scratch my back?\n");
    } else if (strstr(ccat, "fish") != NULL) {
        printf("I love fish!\n");
    } else if (strstr(ccat, "nap") != NULL) {
        printf("I'm taking a nap right now.\n");
    } else if (strstr(ccat, "chase") != NULL) {
        printf("Let's go chase some mice!\n");
    } else {
        printf("I don't understand what you're saying.\n");
    }
    
    return 0;
}