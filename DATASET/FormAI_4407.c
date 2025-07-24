//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Function to determine if a character is a vowel
int isVowel(char letter) {
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        return 1;
    } else {
        return 0;
    }
}

// Function to translate a single word
char* translateWord(char* word) {
    int length = strlen(word);
    char* translation = (char*) malloc(length * sizeof(char)); // Allocate memory for the translated word
    int i;
    for(i = 0; i < length; i++) {
        if(isVowel(word[i])) {
            strcat(translation, "l"); // Add an "l" after each vowel
        }
        strcat(translation, &(word[i])); // Add the rest of the letter(s)
    }
    strcat(translation, "g"); // Add a "g" at the end of each translated word
    return translation;
}

// Function to translate a sentence
void translateSentence(char* sentence) {
    sentence[strlen(sentence)-1] = '\0'; // Remove the newline character at the end of the sentence
    char* word = strtok(sentence, " "); // Get the first word
    while(word != NULL) {
        printf("%s ", translateWord(word)); // Translate and print the word
        word = strtok(NULL, " "); // Get the next word
    }
    printf("\n"); // Print a newline character at the end
}

// Driver function
int main() {
    char sentence[100];
    printf("Enter a sentence in C Alien Language:\n");
    fgets(sentence, 100, stdin);
    translateSentence(sentence);
    return 0;
}