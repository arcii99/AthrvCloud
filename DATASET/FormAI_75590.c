//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 1000

int main() {
    printf("Welcome to the C Word Count Tool \n\n");

    // Initialize variables
    char paragraph[10000];
    char *words[MAX_WORDS];
    char *token;
    int wordCount[MAX_WORDS] = {0};
    int totalWords = 0;
    int uniqueWords = 0;

    printf("Enter a paragraph: \n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize paragraph into individual words
    token = strtok(paragraph, " ");
    while (token != NULL && totalWords < MAX_WORDS) {
        // Store word and update word count
        words[totalWords] = token;
        wordCount[totalWords]++;
        totalWords++;

        // Check if word has already been counted
        int i;
        for (i = 0; i < uniqueWords; i++) {
            if (strcmp(words[totalWords - 1], words[i]) == 0) {
                wordCount[i]++;
                totalWords--;
                break;
            }
        }

        // Update unique word count
        if (i == uniqueWords && totalWords <= MAX_WORDS) {
            uniqueWords++;
        }

        // Get next word
        token = strtok(NULL, " ");
    }

    // Print word count for each unique word
    printf("\nWord Count for Unique Words:\n");
    for (int i = 0; i < uniqueWords; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    // Print total word count and unique word count
    printf("\nTotal Words: %d\n", totalWords);
    printf("Unique Words: %d\n", uniqueWords);

    return 0;
}