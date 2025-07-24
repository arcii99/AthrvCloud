//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of input string

// function to check spelling of given word
void checkSpelling(char *word) {
    char *dictionary[] = {"apple", "banana", "cherry", "orange", "peach", "pear", "pineapple"}; // sample dictionary
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    int i, j, len, match;

    len = strlen(word); // get length of input word
    for (i = 0; i < len; i++) {
        word[i] = tolower(word[i]); // convert input word to lowercase
    }

    match = 0; // variable to keep track of matched dictionary word
    for (i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) { // compare input word with dictionary word
            match = 1; // set match flag to true
            break;
        }
    }

    // print message based on match flag
    if (match == 1) {
        printf("The word \"%s\" is spelled correctly.\n", word);
    } else {
        printf("The word \"%s\" is not found in the dictionary.\n", word);
    }
}

int main() {
    char input[MAX_LEN];

    printf("Enter a word to check its spelling: ");
    fgets(input, MAX_LEN, stdin); // get input from user

    // remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    checkSpelling(input); // check spelling of input word

    return 0;
}