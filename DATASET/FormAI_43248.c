//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

/* Function to count the number of words in a given text */
int countWords(char *text) {
    int totalWords = 0, wordLen = 0; /* totalWords is the counter for the total number of words */

    while (*text != '\0') {
        /* If the character is not a space, increment the word length counter */
        if (!isspace(*text)) {
            wordLen++;
        }
        /* If the character is a space, reset the word length counter and increment the word counter */
        else {
            if (wordLen > 0) {
                totalWords++;
                wordLen = 0;
            }
        }
        text++;
    }

    /* If the last character of the text is not a space, increment the word counter */
    if (wordLen > 0) {
        totalWords++;
    }

    return totalWords;
}

int main() {
    char text[MAX_WORD_LEN+1]; /* text is the input string */
    int numWords;

    printf("Welcome to the C Word Count Tool.\n");
    printf("Please enter the text you would like to count: ");

    /* Read the input string from the user */
    fgets(text, sizeof(text), stdin);

    /* Remove any potential newline character from the input string */
    char *newlinePtr = strchr(text, '\n');
    if (newlinePtr != NULL) {
        *newlinePtr = '\0';
    }

    /* Count the number of words in the input string */
    numWords = countWords(text);

    printf("The number of words in the text is: %d\n", numWords);

    return 0;
}