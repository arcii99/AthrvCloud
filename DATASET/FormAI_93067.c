//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int frequency[26] = {0};
    int i = 0, max_freq = 0;

    printf("Hey Let's play a word frequency counter game!\n");
    printf("Enter a sentence:\n");

    fgets(sentence, 1000, stdin);

    while (sentence[i] != '\0') {
        if (isalpha(sentence[i])) {
            char c = tolower(sentence[i]);
            frequency[c - 'a']++;
            if (frequency[c - 'a'] > max_freq) {
                max_freq = frequency[c - 'a'];
            }
        }
        i++;
    }

    printf("\nHere is the word frequency count in your sentence:\n");

    for (i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            printf("%c occurs %d times: ", i + 'a', frequency[i]);
            for (int j = 0; j < frequency[i]; j++) {
                printf("+");
            }
            printf("\n");
        }
    }

    printf("\nThe most frequent letter is ");

    for (i = 0; i < 26; i++) {
        if (frequency[i] == max_freq) {
            printf("%c", i + 'a');
        }
    }

    printf(" occurring %d times.\n\n", max_freq);

    printf("That was fun! Let's play again sometime!\n");

    return 0;
}