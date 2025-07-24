//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* function to count the words in a string */
int countWords(char* str) {
    int i = 0, count = 0, word = 0;
    char c;

    /* loop through each character in the string */
    while (str[i]) {
        c = str[i];

        /* if character is alphabetic, add to the word */
        if (isalpha(c)) {
            word = 1;
        }
        /* if character is a space and a word exists, increment count */
        else if (isspace(c)) {
            if (word) {
                count++;
                word = 0;
            }
        }
        /* if character is not a space or alphabetic, it is probably punctuation, so don't include it in the word count */
        else {
            word = 0;
        }
        /* move to the next character in the string */
        i++;
    }
    /* if a word exists at the end of the string, add it to the count */
    if (word) {
        count++;
    }
    return count;
}

int main() {
    char sentence[100];
    int count;

    /* get input sentence from user */
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    /* remove newline character from input */
    sentence[strcspn(sentence, "\n")] = 0;

    /* count words in sentence using countWords function */
    count = countWords(sentence);

    /* display result */
    printf("Word count: %d\n", count);

    return 0;
}