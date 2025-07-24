//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Define the maximum length of a word in C Cat Language
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a C Cat Language sentence
#define MAX_WORDS 100

// Define the maximum length of a C Cat Language sentence
#define MAX_SENTENCE_LENGTH (MAX_WORD_LENGTH * MAX_WORDS)

// Define the number of words in the C Cat Language dictionary
#define NUM_DICTIONARY_WORDS 5

// Define the C Cat Language dictionary
char dictionary[NUM_DICTIONARY_WORDS][MAX_WORD_LENGTH] = {
    "meow",
    "purrs",
    "hiss",
    "paws",
    "tail"
};

// Function to check if a given word is present in the C Cat Language dictionary
int isInDictionary(char word[]) {
    for (int i = 0; i < NUM_DICTIONARY_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to translate a C Cat Language sentence into English
void translate(char sentence[]) {
    char word[MAX_WORD_LENGTH];
    char englishSentence[MAX_SENTENCE_LENGTH] = "";
    int j = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            if (isInDictionary(word)) {
                if (strcmp(word, "meow") == 0) {
                    strcat(englishSentence, "I");
                } else if (strcmp(word, "purrs") == 0) {
                    strcat(englishSentence, "am happy");
                } else if (strcmp(word, "hiss") == 0) {
                    strcat(englishSentence, "am angry");
                } else if (strcmp(word, "paws") == 0) {
                    strcat(englishSentence, "hands");
                } else if (strcmp(word, "tail") == 0) {
                    strcat(englishSentence, "back");
                }
            } else {
                strcat(englishSentence, word);
            }
            strcat(englishSentence, " ");
            j = 0;
            memset(word, '\0', sizeof(word));
        } else {
            word[j] = sentence[i];
            j++;
        }
    }
    if (isInDictionary(word)) {
        if (strcmp(word, "meow") == 0) {
            strcat(englishSentence, "I");
        } else if (strcmp(word, "purrs") == 0) {
            strcat(englishSentence, "am happy");
        } else if (strcmp(word, "hiss") == 0) {
            strcat(englishSentence, "am angry");
        } else if (strcmp(word, "paws") == 0) {
            strcat(englishSentence, "hands");
        } else if (strcmp(word, "tail") == 0) {
            strcat(englishSentence, "back");
        }
    } else {
        strcat(englishSentence, word);
    }
    printf("%s\n", englishSentence);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence in C Cat Language:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    translate(sentence);
    return 0;
}