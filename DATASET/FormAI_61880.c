//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold alien language words and their translations
typedef struct {
    char* alien_word;
    char* english_word;
} AlienDictionary;

// Function to translate alien words to english
void translateToEnglish(char* alien_text, int dict_size, AlienDictionary* dictionary) {
    // Split the alien text into words
    char* token = strtok(alien_text, " ");
    while (token != NULL) {
        int translated = 0;
        // Search for the word in the dictionary
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(token, dictionary[i].alien_word) == 0) {
                printf("%s ", dictionary[i].english_word);
                translated = 1;
                break;
            }
        }
        // If the word is not in the dictionary, print it as is
        if (!translated) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    AlienDictionary dictionary[5] = {
        {"kaxaz", "hello"},
        {"blorg", "world"},
        {"xarn", "universe"},
        {"plokr", "goodbye"},
        {"gnen", "computer"}
    };

    char alien_text[100];
    printf("Enter some alien text: ");
    fgets(alien_text, 100, stdin);

    printf("Translating...\n");
    translateToEnglish(alien_text, 5, dictionary);

    return 0;
}