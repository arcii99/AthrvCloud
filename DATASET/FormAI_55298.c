//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the alien language dictionary
char languageDictionary[6][2][50] = {{"hello", "sopela"},
                                    {"goodbye", "exitek"},
                                    {"thank you", "agradeso"},
                                    {"yes", "kasoa"},
                                    {"no", "nonto"},
                                    {"help", "sokana"}};

// Function to translate alien language to human language
void alienLanguageTranslator(char alienLanguage[]) {
    int i, flag = 0;
    printf("\nTranslating '%s' from Alien language to Human language...\n", alienLanguage);
    for(i=0; i<6; i++) {
        if(strcmp(languageDictionary[i][1], alienLanguage) == 0) {
            printf("Translation: %s\n", languageDictionary[i][0]);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("Translation not found.\n");
    }
}

int main() {
    // Take user input for alien language
    char alienLanguage[50];
    printf("Enter a word or phrase in Alien language (or 'exit' to quit): ");
    gets(alienLanguage);

    // Translate each input until the user enters 'exit'
    while(strcmp(alienLanguage, "exit") != 0) {
        alienLanguageTranslator(alienLanguage);
        printf("\nEnter a word or phrase in Alien language (or 'exit' to quit): ");
        gets(alienLanguage);
    }
    printf("Exiting translator...");
    return 0;
}