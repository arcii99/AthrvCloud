//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char new_text[1000];
    int len, i, j = 0, word_count = 0;

    // Input text from user
    printf("Enter text to be processed:\n");
    fgets(text, 1000, stdin);
    text[strlen(text) - 1] = '\0';  // remove newline character

    len = strlen(text);

    // Convert all letters to uppercase
    for(i = 0; i < len; i++) {
        new_text[i] = toupper(text[i]);
    }

    // Count number of words in text
    while(text[j] != '\0') {
        if(text[j] == ' ' || text[j] == '\n' || text[j] == '\t') {
            word_count++;
        }
        j++;
    }

    // Print processed text and number of words
    printf("\nProcessed text:\n%s\n", new_text);
    printf("Number of words: %d\n", word_count + 1);

    return 0;
}