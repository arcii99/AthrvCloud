//FormAI DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 10000

int main()
{
    char input[MAX_INPUT];
    int word_count = 0, in_word = 0, i;
    
    printf("Enter your text below and press Enter:\n");
    fgets(input, MAX_INPUT, stdin);
    
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) { // if the character is alphabetical
            if (!in_word) { // if we're not already in a word, start a new word
                in_word = 1;
                word_count++;
            }
        }
        else {
            in_word = 0; // we're not in a word anymore
        }
    }
    
    printf("Word count: %d\n", word_count);
    return 0;
}