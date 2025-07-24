//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 10000 // maximum length of input string
#define MAXWORDS 1000 // maximum number of words in input string

int countWords(char *input); // function to count words in input string

int main() {
    char input[MAXLENGTH]; // input string
    int wordCount;

    printf("Enter a string: ");
    fgets(input, MAXLENGTH, stdin); // read input string from user

    // trim newline character from input string
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    wordCount = countWords(input); // count words in input string

    printf("Word count: %d\n", wordCount);

    return 0;
}

int countWords(char *input) {
    char *token; // pointer to current word in input string
    char *delimiters = " ,.;:!?\n"; // characters that separate words
    int count = 0; // number of words counted

    token = strtok(input, delimiters); // get first word in input string

    // loop through input string to count words
    while (token != NULL) {
        count++; // increment word count
        token = strtok(NULL, delimiters); // get next word in input string
    }

    return count;
}