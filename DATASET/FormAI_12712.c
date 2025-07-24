//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

// Define the size of the C Alien Language alphabet
#define ALPHABET_SIZE 5

// Define the C Alien Language alphabet
const char *alphabet[] = {"o", "i", "e", "a", "u"};

// Function to translate a C Alien Language word to English
void translate(char *word) {
    int len = strlen(word);
    char translation[len+1];
    int i, j, k;
    for (i = 0; i < len; i++) {
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (word[i] == alphabet[j][0]) {
                // Replace the C Alien Language character with the English equivalent
                translation[i] = "aeiou"[j];
            }
        }
    }
    translation[i] = '\0';
    printf("%s\n", translation);
}

int main() {
    printf("Welcome to the C Alien Language Translator!\n\n");
    
    char word[100];
    do {
        printf("Please enter a word in C Alien Language (or enter 'exit' to quit): ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0'; // Remove the newline character if present
        if (strcmp(word, "exit") != 0) {
            printf("Translation: ");
            translate(word);
        }
    } while (strcmp(word, "exit") != 0);
    
    printf("\nThank you for using the C Alien Language Translator.\n");
    return 0;
}