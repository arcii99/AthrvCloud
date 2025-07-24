//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a word is spelled correctly
bool is_spelled_correctly(char* word) {
    // Array of correctly spelled words
    char* dictionary[] = {"apple", "banana", "orange", "grape", "kiwi", "peach", "pear", "pineapple", "watermelon"};

    // Check if the input word is in the dictionary
    for(int i = 0; i < 9; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return true;
        }
    }

    // If the input word is not in the dictionary, return false
    return false;
}

int main() {
    // Array to hold input word
    char word[25];

    printf("Enter a word to spell check: ");
    scanf("%s", word);

    // Convert the word to lowercase
    for(int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Call the spell checking function and print the result
    if(is_spelled_correctly(word)) {
        printf("%s is spelled correctly!\n", word);
    } else {
        printf("%s is spelled incorrectly!\n", word);
    }

    return 0;
}