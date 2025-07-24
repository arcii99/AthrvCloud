//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[200];
    int numWords = 0, numChars = 0, numLines = 1;

    printf("Enter a sentence or paragraph: \n");
    fgets(sentence, 200, stdin);

    for(int i = 0; sentence[i] != '\0'; i++) {
        if(sentence[i] == '\n') {
            numLines++;
        }
        if(isalnum(sentence[i])) {
            numChars++;
        }
        if(sentence[i] == ' ' && isalnum(sentence[i-1])) {
            numWords++;
        }
    }

    // adding 1 to numWords to include the last word in the sentence
    numWords++;

    printf("Number of words in the sentence: %d\n", numWords);
    printf("Number of characters in the sentence: %d\n", numChars);
    printf("Number of lines in the sentence: %d\n", numLines);

    return 0;
}