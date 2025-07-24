//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if given string is spam or not
int isSpam(char *str) {
    // array of spam keywords
    char *keywords[] = {"earn", "money", "cash", "free", "click", "guaranteed", "sale", "discount", "limited time", "offer"};
    int numKeywords = 10;

    // loop through all the words in the input string
    char *word;
    word = strtok(str, " ");
    while (word != NULL) {
        // loop through all the keywords and check if the word is a spam keyword
        for (int i=0; i<numKeywords; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                // word is a spam keyword, return true
                return 1;
            }
        }

        // get next word
        word = strtok(NULL, " ");
    }

    // no spam keywords found, return false
    return 0;
}

int main() {
    // input string to check for spam
    char str[1000];

    // get input from user
    printf("Enter a string to check for spam: ");
    fgets(str, 1000, stdin);

    // remove the newline character from the input string
    str[strcspn(str, "\n")] = 0;

    // check if input string is spam or not
    if (isSpam(str)) {
        printf("%s is spam.", str);
    } else {
        printf("%s is not spam.", str);
    }

    return 0;
}