//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if character is a valid letter
int isLetter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    }
    return 0;
}

// Function to check if word is spelled correctly
int spellCheck(char *word, char **dictionary, int size) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            found = 1;
            break;
        }
    }
    return found;
}

int main() {
    char *dictionary[] = { "hello", "world", "programming", "language", "computer", 
                           "science", "algorithm", "variable", "function", "data" };
    int size = 10;  // size of dictionary array
    char input[100];    // initialize input buffer
    printf("Enter text to spell check: ");
    // readline function to read input from user
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char word[100];
        int length = strlen(input);   // length of input string
        int j = 0;  // index for word character array
        for (int i = 0; i < length; i++) {
            if (isLetter(input[i])) {
                word[j++] = tolower(input[i]);  // append letters in lowercase
            } else {
                if (j > 0) {
                    word[j] = '\0'; // terminate word string
                    if (!spellCheck(word, dictionary, size)) {
                        printf("'%s' is spelled incorrectly\n", word);
                    }
                    j = 0;  // reset word index
                }
            }
        }
    }
    return 0;
}