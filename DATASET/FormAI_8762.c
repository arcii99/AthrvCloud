//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int wordCount = 0;
    printf("Please enter the text to count the number of words:\n");
    fgets(text, 1000, stdin);

    int i = 0;
    while (text[i] != '\0') {
        // if the current character is whitespace or a newline,
        // we assume a new word has started
        if (isspace(text[i]) || text[i] == '\n') {
            wordCount++;
        }

        i++;
    }

    // the last word is not counted in the loop, so we have to add one more
    wordCount++;

    printf("The text contains %d words.\n", wordCount);

    return 0;
}