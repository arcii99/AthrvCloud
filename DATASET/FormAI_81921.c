//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate the alien language
void translate(char* word) {
    int length = strlen(word);

    // Check if the word contains the letter 'k'
    if (strstr(word, "k")) { 
        printf("The word '%s' in alien language is: ", word);

        for (int i = 0; i < length; i++) {
            // Replace the letter 'k' with 'h'
            if (word[i] == 'k') {
                printf("h");
            } else {
                printf("%c", word[i]);
            }
        }

        printf("\n");
    } else {
        printf("The word '%s' is not in alien language.\n", word);
    }
}

int main() {
    char input[50];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a word in the alien language: ");
    scanf("%s", input);

    translate(input);

    return 0;
}