//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of the input text */
#define MAX_LENGTH 1000

/* Define the maximum length of each word */
#define MAX_WORD_LENGTH 50

/* Define a function to strip whitespaces */
char* strip_whitespace(char* str) {
    char* end;

    /* Trim leading space */
    while(isspace((unsigned char)*str)) str++;

    /* All spaces? */
    if(*str == 0)
      return str;

    /* Trim trailing space */
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    /* Write new null terminator character */
    *(end+1) = 0;

    return str;
}

int main() {
    char input[MAX_LENGTH];
    char word[MAX_WORD_LENGTH];
    char* stripped_word;
    int i, j, k, length;
    int word_count = 0;

    /* Prompt the user for input */
    printf("Enter text: \n");
    fgets(input, MAX_LENGTH, stdin);

    /* Loop through input string */
    length = strlen(input);
    for(i = 0; i < length; i++) {
        /* Check if character is whitespace or punctuation */
        if(isspace(input[i]) || ispunct(input[i])) {
            /* If word buffer is not empty, process word */
            if(word_count > 0) {
                word[word_count] = '\0';
                stripped_word = strip_whitespace(word);
                printf("%s\n", stripped_word);
                memset(word, 0, sizeof(word));
                word_count = 0;
            }
        } else {
            /* Add character to word buffer */
            word[word_count] = input[i];
            word_count++;
            /* If word buffer is full, print error message and exit */
            if(word_count == MAX_WORD_LENGTH) {
                printf("Error: word too long\n");
                return 1;
            }
        }
    }
    /* Process the last word in the input string */
    if(word_count > 0) {
        word[word_count] = '\0';
        stripped_word = strip_whitespace(word);
        printf("%s\n", stripped_word);
    }
    return 0;
}