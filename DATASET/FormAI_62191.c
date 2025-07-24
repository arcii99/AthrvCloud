//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
/* 
 * This is a program to count the frequency of words starting with the letter "C". 
 * Developed by Linus Torvalds.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

/* Function to check if a character is a valid alphabet character */
int is_valid_char(char c) {
    return isalpha(c) || c == '-';
}

/* Function to check if a word starts with the letter "C" */
int starts_with_c(char *word) {
    return (word[0] == 'C' || word[0] == 'c');
}

/* Function to update the word count */
void update_word_count(char *word, int *word_count) {
    if (starts_with_c(word)) {
        (*word_count)++;
    }
}

/* Function to print the word count for "C" words */
void print_word_count(int word_count) {
    printf("The number of words starting with the letter \"C\" is: %d\n", word_count);
}

int main() {
    char input_string[MAX_WORD_LENGTH * MAX_WORDS];
    char *current_word;
    char delim[] = " \n\t";
    int word_count = 0;
    
    printf("Enter your text: ");
    fgets(input_string, sizeof(input_string), stdin);
    current_word = strtok(input_string, delim);
    
    while (current_word != NULL) {
        if (strlen(current_word) <= MAX_WORD_LENGTH) {
            int i = 0;
            int valid = 1;
            for (i = 0; i < strlen(current_word); i++) {
                if (!is_valid_char(current_word[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                update_word_count(current_word, &word_count);
            }
        }
        current_word = strtok(NULL, delim);
    }
    
    print_word_count(word_count);
    
    return 0;
}