//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main() {
    char words[MAX_WORDS][50];
    int frequency[MAX_WORDS];
    int word_count = 0;

    printf("Enter a sentence: ");

    // Read input sentence from user
    char c;
    char word[50];
    int idx = 0;
    while ((c = getchar()) != '\n' && idx < 50) {
        if (isalpha(c)) {
            word[idx++] = c;
        } else {
            // End of word
            if (idx > 0) {
                word[idx] = '\0';

                // Check if the word already exists in the array
                int found = 0;
                for (int i = 0; i < word_count; i++) {
                    if (strcmp(word, words[i]) == 0) {
                        frequency[i]++;
                        found = 1;
                        break;
                    }
                }

                // If the word does not exist, add it to the array
                if (!found) {
                    strcpy(words[word_count], word);
                    frequency[word_count] = 1;
                    word_count++;
                }

                // Clear word buffer
                idx = 0;
            }
        }
    }

    // Print the frequency of each word
    printf("\nWord frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}