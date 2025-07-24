//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to check if a word is spelled correctly
int check_spelling(char* word) {
    char dictionary[5][10] = { // Sample dictionary
        "banana",
        "apple",
        "mango",
        "peach",
        "kiwi"
    };
    
    int size = sizeof(dictionary) / sizeof(dictionary[0]); // Get the number of words in the dictionary
    
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found in the dictionary
        }
    }
    
    return 0; // Word not found in the dictionary
}

int main() {
    char sentence[200]; // User input sentence
    printf("Enter a sentence to spell check:\n");
    fgets(sentence, 200, stdin);
    
    char* word = strtok(sentence, " ,.!?"); // Get the first word in the sentence
    int errors = 0; // Counter for number of spelling errors
    printf("Spell checking result:\n");
    
    while (word != NULL) {
        if (check_spelling(word) == 0) { // Word not found in dictionary
            printf("%s is not spelled correctly\n", word);
            errors++;
        }
        word = strtok(NULL, " ,.!?"); // Get the next word in the sentence
    }
    
    if (errors == 0) {
        printf("No spelling errors found\n");
    } else {
        printf("Total spelling errors found: %d\n", errors);
    }
    
    return 0;
}