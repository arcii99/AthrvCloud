//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {

    char word[1000], c;
    int count = 0, freq[26] = {0};

    printf("Enter a sentence: (after the apocalypse)\n");

    // Collect user input
    while ((c = getchar()) != '\n') {
        word[count] = c;
        count++;
    }

    // Loop through sentence and count frequency of each letter
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            freq[word[i] - 'a']++;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z') {
            freq[word[i] - 'A']++;
        }
    }

    printf("\nFrequency of each letter:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', freq[i]);
    }

    return 0;
}