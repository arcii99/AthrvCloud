//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>

// Define the alien language dictionary
const char* dictionary[] = {
    "zkylu", // hello
    "kek", // yes
    "tac", // no
    "fedyx", // goodbye
};

// Main function to run the program
int main() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a word in the alien language (no spaces):\n");

    char word[100];
    scanf("%s", word);

    // Search for the word in the dictionary
    int found = 0;
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        if (strcmp(dictionary[i], word) == 0) {
            printf("Translation: ");
            // Print the translation in English
            switch (i) {
                case 0:
                    printf("Hello\n");
                    break;
                case 1:
                    printf("Yes\n");
                    break;
                case 2:
                    printf("No\n");
                    break;
                case 3:
                    printf("Goodbye\n");
                    break;
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sorry, the word was not found in the dictionary.\n");
    }

    return 0;
}