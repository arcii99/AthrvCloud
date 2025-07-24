//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

// Function to translate a word from C Alien Language to English
void translate(char *word) {
    int i = 0;
    // Check if the word starts with a vowel
    if (word[0] == 'x' || word[0] == 'z') {
        printf("The word \"%s\" in C Alien Language is not translatable to English.\n", word);
        return;
    }
    if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
        printf("The word \"%s\" in C Alien Language translates to \"the %s\" in English.\n", word, word);
        return;
    }
    // Find the first vowel in the word
    for (i = 1; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            break;
        }
    }
    // Check if there were no vowels found in the word
    if (i == strlen(word)) {
        printf("The word \"%s\" in C Alien Language does not contain a vowel and is not translatable to English.\n", word);
        return;
    }
    // Translate the word to English
    printf("The word \"%s\" in C Alien Language translates to \"%s%s\" in English.\n", word, &word[i], word);
}

int main() {
    char input[100];
    printf("Welcome to the C Alien Language Translator!\n");
    while (1) {
        printf("Enter a word in C Alien Language or 'q' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            printf("Thank you for using the C Alien Language Translator!\n");
            break;
        }
        translate(input);       
    }
    return 0;   
}