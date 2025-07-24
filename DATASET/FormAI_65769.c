//FormAI DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char sentence[100];   // array to store user input string
    int word_count = 0;   // variable to count number of words in string
    int i;

    printf("Enter a sentence:\n");
    fgets(sentence, 100, stdin);    // reads user input string

    for(i=0;sentence[i]!='\0';i++) {

        // checks if current character is a whitespace or newline character
        if (isspace(sentence[i]) || sentence[i] == '\n') {
            word_count++;   // increments word_count if whitespace or newline found
        }
    }
    
    // handles edge case where no whitespaces or newlines found and only one word in sentence
    if (word_count == 0) {
        word_count = 1;
    }

    // prints word count and original input sentence
    printf("Number of words in sentence: %d\n", word_count);
    printf("Input sentence: %s\n", sentence);

    return 0;
}