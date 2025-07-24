//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main() {
    char c, word[MAX_WORD_LENGTH+1];
    int wordIndex = 0, totalWords = 0;
    int freqs[MAX_WORD_LENGTH] = {0};

    printf("Enter a sentence:\n");
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            if (wordIndex < MAX_WORD_LENGTH) {
                word[wordIndex++] = c;
            }
        } else if(wordIndex > 0) {
            // Found the end of a word, so count it
            word[wordIndex] = '\0';
            freqs[strlen(word)-1]++;
            totalWords++;
            wordIndex = 0;
        }
    }

    // Check for the last word (if not followed by non-alpha characters)
    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        freqs[strlen(word)-1]++;
        totalWords++;
    }

    // Output the frequency counts
    printf("\nWord Length\tFrequency\t%% of Total Words\n");
    printf("------------------------------------------------------\n");
    for (int length=1; length<=MAX_WORD_LENGTH; length++) {
        int freq = freqs[length-1];
        float percentage = ((float) freq / totalWords) * 100.0;
        printf("%d\t\t%d\t\t%.1f%%\n", length, freq, percentage);
    }

    return 0;
}