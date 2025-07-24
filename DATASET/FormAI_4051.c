//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

int main() {
    char input_string[1000];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int i, j, k;
    int word_count = 0;

    printf("Please enter a string: ");
    fgets(input_string, 1000, stdin); // get input string from user

    for(i = 0; input_string[i] != '\0'; i++) {
        if(input_string[i] == ' ' || input_string[i] == '\n' || input_string[i] == '\t') {
            if(count > 0) {
                // process word
                for(k = 0, j = i - count; j < i; j++, k++) {
                    if(isalpha(input_string[j])) {
                        word[k] = tolower(input_string[j]);
                    } else {
                        k--;
                    }
                }
                word[k] = '\0'; // add null terminator to word

                if(strlen(word) > 0) { // make sure word is not empty
                    word_count++; // count the words

                    // print the word and its frequency
                    printf("%s\t%d\n", word, word_count);
                }
            }
            count = 0;
        } else {
            count++;
        }
    }

    return 0;
}