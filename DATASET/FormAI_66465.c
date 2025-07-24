//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

// Function to determine if a character is a valid Alien language letter
int isAlienLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to translate a single word from Alien language to English
char* translateWord(char* alienWord) {
    int length = strlen(alienWord);
    char englishWord[length];
    
    for (int i = 0; i < length; i++) {
        // The Alien language has a unique way of translating letters
        // a = z, b = y, c = x, d = w, e = v, f = u, ...
        englishWord[i] = 'a' + ('z' - alienWord[i]);
    }
    
    // We must return a pointer, so that the translated word can be used later
    return englishWord;
}

// Function to translate an entire sentence from Alien language to English
void translateSentence(char* alienSentence) {
    char* token = strtok(alienSentence, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            char* englishWord = translateWord(token);
            printf("%s ", englishWord);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char sentence[100];
    printf("Please enter an Alien language sentence to be translated: ");
    scanf("%[^\n]s", sentence);
    translateSentence(sentence);
    return 0;
}