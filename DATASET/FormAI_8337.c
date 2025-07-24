//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_words(char *string);

int main(void)
{
    char text[1000];

    printf("Enter text: ");
    fgets(text, 1000, stdin);

    int word_count = count_words(text);
    printf("Word count: %d\n", word_count);

    return 0;
}

int count_words(char *string)
{
    int count = 0;
    int is_word = 0;

    // Loop through each character in the string
    for (int i = 0; i < strlen(string); i++) {
        // If the current character is a letter or digit
        if (isalnum(string[i])) {
            // If we're not already in a word, start a new one
            if (!is_word) {
                count++;
                is_word = 1;
            }
        } else {
            // If the current character is not a letter or digit, we're not in a word
            is_word = 0;
        }
    }

    return count;
}