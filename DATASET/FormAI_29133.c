//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_SIZE 100

bool is_palindrome(char word[]);

int main(void) {
    char word[MAX_WORD_SIZE];
    printf("Enter a word to check if it is a palindrome:\n");
    fgets(word, MAX_WORD_SIZE, stdin);
    // Remove newline character from input
    if (word[strlen(word) - 1] == '\n') {
        word[strlen(word) - 1] = '\0';
    }
    
    if (is_palindrome(word)) {
        printf("The word \"%s\" is a palindrome\n", word);
    } else {
        printf("The word \"%s\" is not a palindrome\n", word);
    }
    return 0;
}

bool is_palindrome(char word[]) {
    char sanitized_word[MAX_WORD_SIZE];
    // Sanitize word by removing non-alpha characters and converting to lowercase
    int index = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            sanitized_word[index] = tolower(word[i]);
            index++;
        }
    }
    sanitized_word[index] = '\0'; // Terminate the string

    int start = 0;
    int end = strlen(sanitized_word) - 1;
    while (start < end) {
        if (sanitized_word[start] != sanitized_word[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}