//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <string.h>

/* This is a program for calculating the count of words in a given sentence */

int main() {
    char sentence[100];
    int count = 0, i;

    printf("Please enter a sentence: ");
    gets(sentence);

    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ' && sentence[i-1] != ' ') {
            count++;
        }
    }

    if (sentence[strlen(sentence) - 1] != ' ') {
        count++;
    }

    printf("The number of words in the sentence is: %d", count);

    return 0;
}