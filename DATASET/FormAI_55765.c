//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

void stripPunctuation(char *str) {
    char *p = str;
    while (*p) {
        if (ispunct(*p)) {
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }
}

int main() {
    char *text = "This is a sentence. Another sentence follows, yes indeed! The last sentence is right here.";
    char *words[MAX_NUM_WORDS];
    int freqs[MAX_NUM_WORDS] = {0};
    int wordCount = 0;

    // convert text to lowercase and strip out punctuation
    char *tmp = strdup(text);
    for (int i = 0; i < strlen(tmp); i++) {
        tmp[i] = tolower(tmp[i]);
    }
    stripPunctuation(tmp);

    // split text into words and count frequency of each word
    char *saveptr;
    char *token = strtok_r(tmp, " ", &saveptr);
    while (token != NULL) {
        char *word = strdup(token);
        int foundIdx = -1;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                foundIdx = i;
                break;
            }
        }
        if (foundIdx == -1) {
            words[wordCount] = word;
            freqs[wordCount] = 1;
            wordCount++;
        } else {
            freqs[foundIdx]++;
            free(word);
        }
        token = strtok_r(NULL, " ", &saveptr);
    }

    // print out frequency table
    printf("Word\t\tFrequency\n");
    printf("=====================\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%-20s%d\n", words[i], freqs[i]);
    }

    // free memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(tmp);

    return 0;
}