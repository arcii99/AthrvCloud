//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char alien_language[50];

    printf("Enter the alien language: ");
    scanf("%s", &alien_language);

    printf("\nTranslation: ");

    // Code for translating alien language to English
    
    if (strcmp(alien_language, "kxth") == 0) {
        printf("Hello");
    }
    else if (strcmp(alien_language, "trzpl") == 0) {
        printf("Goodbye");
    }
    else if (strcmp(alien_language, "wymb") == 0) {
        printf("Thank you");
    }
    else if (strcmp(alien_language, "qbgf") == 0) {
        printf("Please");
    }
    else if (strcmp(alien_language, "dvmk") == 0) {
        printf("Sorry");
    }
    else {
        printf("Translation not found");
    }

    return 0;
}