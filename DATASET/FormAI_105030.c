//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], word[1000];
    int count = 0;

    printf("Please enter a piece of text: ");
    fgets(text, sizeof(text), stdin);

    printf("Please enter a word to find: ");
    fgets(word, sizeof(word), stdin);

    // Remove new line characters from the inputs
    text[strcspn(text, "\n")] = '\0';
    word[strcspn(word, "\n")] = '\0';
    
    int len = strlen(word);
    for(int i = 0; i < strlen(text); i++) {
        // Use strncmp function to compare substrings of text with the word
        if(strncmp(text + i, word, len) == 0) {
            count++;
        }
    }

    printf("The word '%s' occurs %d times in the given text.\n", word, count);

    return 0;
}