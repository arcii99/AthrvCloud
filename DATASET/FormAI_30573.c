//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <string.h>

// defining a struct to hold a dictionary word and its translation
struct WordTranslation {
    char word[20];
    char translation[20];
};

// initializing the dictionary with some words and their translations
struct WordTranslation dictionary[] = {
    {"meow", "hello"},
    {"purr", "thank you"},
    {"hiss", "go away"},
    {"scratch", "help me"},
    {"pounce", "surprise!"},
    {"lick", "nice to meet you"}
};

// function to translate a given word to its C Cat Language counterpart
char* translateWord(char* word) {
    // iterating through the dictionary to find a match for the given word
    for(int i=0; i<6; i++) {
        if(strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].translation;
        }
    }
    // if no match is found, returning the original word
    return word;
}

// function to translate a given sentence to its C Cat Language counterpart
void translateSentence(char* sentence) {
    char* word = strtok(sentence, " ");
    while(word != NULL) {
        printf("%s ", translateWord(word));
        word = strtok(NULL, " ");
    }
    printf("\n");
}

// main function to test the translator
int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence to translate: ");
    char sentence[100];
    fgets(sentence, 100, stdin);
    printf("Original Sentence: %s", sentence);
    printf("Translated Sentence: ");
    translateSentence(sentence);
    return 0;
}