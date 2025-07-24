//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000];
    int length = 0, wordCount = 0, i;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); // use fgets to allow spaces to be counted

    length = strlen(sentence);

    // check if sentence ends with '\n'
    if (sentence[length - 1] == '\n') {
        sentence[length - 1] = '\0';
        length--;
    }

    for (i = 0; i < length; i++) {
        if (sentence[i] == ' ') { // if space, increase word count
            wordCount++;
        }
    }

    // Add 1 to word count since the last word is not followed by a space
    wordCount++;

    printf("The sentence \"%s\" has %d words.\n", sentence, wordCount);

    return 0;
}