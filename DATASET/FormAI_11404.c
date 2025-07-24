//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Sample dictionary
char* catDict[] = {
    "meow",
    "purr",
    "hiss",
    "scratch",
    "play",
    "sleep",
    "eat",
    "drink"
};

// Sample translations
char* englishTranslate[] = {
    "Hello",
    "How are you?",
    "I love you",
    "Goodbye",
    "What's your name?",
    "Nice to meet you",
    "Where are you from?",
    "Thank you",
    "I'm sorry"
};

int main() {
    // Ask user for input in C Cat Language
    printf("Enter your C Cat Language phrase: ");
    char cCatPhrase[100];
    fgets(cCatPhrase, 100, stdin);

    // Parse C Cat Language phrase
    char* word = strtok(cCatPhrase, " \n");
    while (word != NULL) {
        // Search for word in dictionary and translate
        int i;
        for (i=0; i<8; i++) {
            if (strcmp(word, catDict[i]) == 0) {
                printf("%s ", englishTranslate[i]);
                break;
            }
        }
        word = strtok(NULL, " \n");
    }
    printf("\n");

    return 0;
}