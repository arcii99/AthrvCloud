//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100   // Define maximum word length

int main() {
    char dictionary[1000][MAX_WORD_LENGTH];   // Define pre-defined dictionary
    char input_text[MAX_WORD_LENGTH];   // Define input text
    int num_words = 0;   // Set count of dictionary words to 0
    
    // Open dictionary file and store words into dictionary array
    FILE *dict = fopen("dictionary.txt", "r");
    while (fgets(dictionary[num_words], MAX_WORD_LENGTH, dict)) {
        // Remove newline character from end of dictionary word
        dictionary[num_words][strcspn(dictionary[num_words], "\n")] = 0;
        num_words++;
    }
    fclose(dict);
    
    // Prompt user for input text
    printf("Enter text to spell-check:\n");
    fgets(input_text, MAX_WORD_LENGTH, stdin);
    
    // Tokenize input text into individual words and compare against dictionary
    char *word = strtok(input_text, " \r\n\t");
    while (word != NULL) {
        int found = 0;   // Set flag for match to false
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i]) == 0) {   // If word found in dictionary
                found = 1;   // Set flag for match to true
                break;
            }
        }
        // Print results of spell-check for current word
        if (found) {
            printf("%s is spelled correctly.\n", word);
        } else {
            printf("%s is misspelled.\n", word);
        }
        word = strtok(NULL, " \r\n\t");
    }
    
    return 0;
}