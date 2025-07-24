//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[500];
    char word[50];
    int counter = 0;
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Enter a word to search for:\n");
    fgets(word, sizeof(word), stdin); 
    word[strlen(word) - 1] = '\0'; // Remove the newline character from the word

    char *token = strtok(sentence, " .,:;!?"); // Tokens are separated by spaces and punctuation marks

    while (token != NULL) {
        if (strcmp(token, word) == 0) { // Compare token with word
            counter++;
        }
        token = strtok(NULL, " .,:;!?"); // Get next token
    }
    if (counter > 0) {
        printf("%s appears %d times in the sentence.\n", word, counter);
    } else {
        printf("%s is not found in the sentence.\n", word);
    }
    return 0;
}