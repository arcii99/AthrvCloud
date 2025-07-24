//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Function to count the frequency of each word in the given text
void countFrequency(char text[]) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS];
    int i, j, k, count;

    // Tokenize the text into individual words
    i = 0;
    j = 0;
    k = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '!') {
            words[j][k] = '\0';
            j++;
            k = 0;
        } else {
            words[j][k] = text[i];
            k++;
        }
        i++;
    }
    words[j][k] = '\0';
    count = j+1;

    // Count the frequency of each word
    for (i = 0; i < count; i++) {
        frequency[i] = 1;
        for (j = i+1; j < count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequency[i]++;
                words[j][0] = '\0';
            }
        }
    }

    // Print the word frequency counts
    printf("Word\t\tFrequency\n");
    printf("----\t\t---------\n");
    for (i = 0; i < count; i++) {
        if (words[i][0] != '\0') {
            printf("%-15s %d\n", words[i], frequency[i]);
        }
    }
}

int main() {
    // Example text
    char text[] = "In the year 2077, after the Great War, life on Earth is very different.";

    // Count the frequency of each word in the text
    countFrequency(text);

    return 0;
}