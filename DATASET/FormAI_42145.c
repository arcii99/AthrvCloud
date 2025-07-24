//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str) {

    int count = 0;

    // Uncomment this line to ignore spaces and punctuation marks
    // char *token = strtok(str, " ,.;:-—?!");

    char *token = strtok(str, " ");

    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

int main() {

    printf("Welcome to C Word Count Tool!\n");
    printf("Enter a sentence or paragraph:\n");

    char input[1000];
    fgets(input, 1000, stdin); // Read user input from standard input

    // Removing trailing newline character from user input
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n')
        input[ln] = '\0';

    // Counting words in user input string
    int words = countWords(input);

    printf("Your input has %d words!\n", words);

    return 0;
}