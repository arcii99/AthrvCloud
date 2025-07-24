//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // maximum length of a word
#define MAX_WORDS 100000   // maximum number of words that can be read from file

int main() {
    char word[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int i, j, k, n, found, count;

    // initialize frequency count array
    for (i = 0; i < MAX_WORDS; i++) {
        freq[i] = 0;
    }

    // read words from file until end of file is reached
    i = 0;
    while (scanf("%s", word) != EOF) {
        // remove non-alphabetic characters from word
        n = 0;
        for (j = 0; word[j] != '\0'; j++) {
            if (isalpha(word[j])) {
                word[n++] = tolower(word[j]);
            }
        }
        word[n] = '\0';

        // check if word is already in words array
        found = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[j], word) == 0) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        // if word is not already in words array, add it
        if (!found && i < MAX_WORDS) {
            strcpy(words[i], word);
            freq[i] = 1;
            i++;
        }
    }

    // output word frequency count
    count = 0;
    for (k = 1; k <= MAX_WORDS; k++) {
        found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (freq[i] == k) {
                if (!found) {
                    printf("%4d %s\n", k, words[i]);
                    found = 1;
                }
                count++;
            }
        }
        if (count == i) {
            break;
        }
    }

    return 0;
}