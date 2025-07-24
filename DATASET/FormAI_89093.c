//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <string.h>

void countWords(char sentence[], int *wordCount, int *charCount) {

    int i = 0;
    int spaceCount = 0;
    *charCount = strlen(sentence);

    // Counting number of words
    while(sentence[i] != '\0') {
        if(sentence[i] == ' ') {
            spaceCount++;
        }
        i++;
    }
    *wordCount = spaceCount + 1;
}

int main() {

    char sentence[1000];
    int wordCount, charCount;

    // Asking user for input
    printf("\nEnter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Calling countWords function
    countWords(sentence, &wordCount, &charCount);

    // Displaying the word count and character count
    printf("\nWord count: %d", wordCount);
    printf("\nCharacter count: %d\n", charCount);

    return 0;
}