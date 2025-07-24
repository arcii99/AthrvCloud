//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language translation dictionary
struct Translation {
    char* alienWord;
    char* englishWord;
};

struct Translation alienDictionary[] = {
    {"blorg", "hello"},
    {"skrox", "thank you"},
    {"fliptop", "goodbye"},
    {"yargh", "please"},
    {"zappo", "yes"},
    {"narf", "no"},
    {"ploob", "how are you?"},
    {"gazoinks", "excuse me"},
    {"quibbly", "sorry"}
};

// Define the main function for the translation program
int main(void) {
    char input[50];
    int numWords = sizeof(alienDictionary) / sizeof(struct Translation);

    // Prompt the user to enter an alien word
    printf("Enter an alien word to translate: ");
    scanf("%s", input);

    // Search for a match in the dictionary
    for (int i = 0; i < numWords; i++) {
        if (strcmp(input, alienDictionary[i].alienWord) == 0) {
            printf("Translation: %s\n", alienDictionary[i].englishWord);
            return 0;
        }
    }

    // Print an error message if no match is found
    printf("Sorry, that word is not in our dictionary.\n");
    return 0;
}