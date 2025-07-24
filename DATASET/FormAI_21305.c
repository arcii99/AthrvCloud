//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *phrase) { // Function to count the words in a phrase
    int count = 0;
    int len = strlen(phrase);
    int flag = 0;

    for (int i = 0; i < len; i++) {
        if (phrase[i] == ' ' || phrase[i] == '\n' || phrase[i] == '\t') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            count++;
        }
    }

    return count;
}

int main() {
    char phrase[100]; // Array to store the input phrase
    printf("Enter a phrase:\n");
    fgets(phrase, 100, stdin); // Function to read input

    int wordCount = countWords(phrase);
    printf("\nThe number of words in the phrase is: %d", wordCount);

    return 0;
}