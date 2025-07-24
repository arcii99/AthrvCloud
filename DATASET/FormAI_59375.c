//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

// Function to check if a character is a consonant
int isConsonant(char ch) {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
        return 0; // Return 0 if it is a vowel
    } else {
        return 1; // Return 1 if it is a consonant
    }
}

// Function to convert a word to Cat language
void convertToCatLanguage(char* word) {
    char translatedWord[100];
    int i, j, len = strlen(word);

    for(i=0, j=0; i<len; i++) {
        if(isConsonant(word[i])) { // If it is a consonant
            translatedWord[j++] = word[i];
            translatedWord[j++] = 'o';
            translatedWord[j] = word[i];
        } else { // If it is a vowel
            translatedWord[j++] = word[i];
        }
    }

    translatedWord[j] = '\0'; // Adding the terminator

    printf("Translation to Cat language: %s\n", translatedWord);
}

// Main function
int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", &word); // Reading a word from user input

    convertToCatLanguage(word); // Converting the word to Cat language

    return 0;
}