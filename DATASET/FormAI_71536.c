//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to check if the given character is a vowel or not
int isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

// Function to translate the given word from the Alien Language
char* alienTranslator(char *word) {
    // Check if the first character of the word is a consonant or not
    if(!isVowel(word[0])) {
        // Store the first character of the word and remove it
        char temp = word[0];
        for(int i=0; i<strlen(word); i++) {
            word[i] = word[i+1];
        }
        word[strlen(word)-1] = temp;
    }
    // Append 'z' and 'a' to the end of the word
    strcat(word, "za");
    // Replace all vowels with 'e'
    for(int i=0; i<strlen(word); i++) {
        if(isVowel(word[i])) {
            word[i] = 'e';
        }
    }
    // Return the translated word
    return word;
}

int main() {
    // Get the word from the user
    char word[100];
    printf("Enter the word in Alien Language: ");
    scanf("%s", word);

    // Translate the word into English
    char translatedWord[100];
    strcpy(translatedWord, alienTranslator(word));

    // Display the translated word
    printf("The translated word is: %s\n", translatedWord);

    return 0;
}