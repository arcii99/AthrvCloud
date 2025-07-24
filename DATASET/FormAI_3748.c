//FormAI DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a valid letter
int is_valid_letter(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    int i;
    
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check the spelling of a word
void spell_check_word(char *word, char **dictionary) {
    int i;
    char lower_word[50];
    int found = 0;
    
    // Convert word to lowercase
    strcpy(lower_word, word);
    to_lowercase(lower_word);
    
    // Check if word is in dictionary
    for (i = 0; dictionary[i]; i++) {
        if (strcmp(dictionary[i], lower_word) == 0) {
            found = 1;
            break;
        }
    }
    
    // Print result
    if (found) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }
}

int main() {
    char input[100];
    char *word;
    char *dictionary[] = { "apple", "banana", "cat", "dog", "elephant", NULL };
    int i, j;
    
    // Get input string from user
    printf("Enter text to spell check:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    
    // Split string into words and spell check each one
    word = strtok(input, " ");
    while (word != NULL) {
        // Check each character in word and remove non-letter characters
        j = 0;
        for (i = 0; word[i]; i++) {
            if (is_valid_letter(word[i])) {
                word[j++] = word[i];
            }
        }
        word[j] = '\0';
        
        // Spell check word
        spell_check_word(word, dictionary);
        
        // Get next word
        word = strtok(NULL, " ");
    }
    
    return 0;
}