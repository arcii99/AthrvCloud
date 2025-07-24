//FormAI DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 50

// A structure to store a word and its frequency
struct Word {
    char word[WORD_SIZE]; // word buffer
    int frequency; // frequency of the word
};

// A function to compare two words based on their frequency
int compare(const void *w1, const void *w2) {
    const struct Word *word1 = w1;
    const struct Word *word2 = w2;
    return word2->frequency - word1->frequency;
}

// A function to check the spelling of a word
int check_spelling(const char *word, const char *dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // The word is in the dictionary
        }
    }
    return 0; // The word is not in the dictionary
}

int main() {
    char text[1000]; // input text buffer
    char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry"}; // dictionary
    const int n = sizeof(dictionary) / sizeof(dictionary[0]); // number of words in the dictionary
    struct Word words[n]; // words buffer
    int count = 0; // number of words in the text
    
    // read the text from the user
    printf("Enter a text:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove the trailing newline
    
    // tokenize the text into words
    char *word = strtok(text, " ,.-");
    while (word != NULL) {
        if (!check_spelling(word, dictionary, n)) {
            // the word is misspelled, add it to the list
            strcpy(words[count].word, word);
            words[count].frequency = 1; // initialize the frequency to 1
            count++;
        }
        else {
            // the word is correctly spelled, update its frequency
            for (int i = 0; i < count; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++; // increment the frequency
                    break;
                }
            }
        }
        word = strtok(NULL, " ,.-");
    }
    
    // sort the words by frequency
    qsort(words, count, sizeof(struct Word), compare);
    
    // print the misspelled words and their frequency
    printf("Misspelled words:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    
    return 0;
}