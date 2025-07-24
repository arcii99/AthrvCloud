//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main(void) {
    char current_char, word[MAX_WORD_LENGTH];
    int i = 0, word_count = 0;

    printf("Enter your text: ");

    while ((current_char = getchar()) != EOF) {

        if (isalnum(current_char)) { // check if current character is alphanumeric
            word[i++] = tolower(current_char); // add lowercase version of current character to word
        }
        else if (i > 0) { // if current character is not alphanumeric and we have already started a word
            word[i] = '\0'; // terminate word
            word_count++; // increment word count

            printf("%s: %d\n", word, (int) strlen(word)); // print word and its length
            i = 0; // reset the word counter
        }

        if (current_char == '\n') { // stop reading if we reach a new line
            break;
        }
    }

    printf("Word count: %d", word_count);

    return 0;
}