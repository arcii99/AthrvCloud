//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAXWORDS 5000

struct WordInfo {
    char word[MAX_WORD_LEN];
    int count;
};

int cmpfunc(const void *a, const void *b) { 
    const struct WordInfo *w1 = a;
    const struct WordInfo *w2 = b;
    return w2->count - w1->count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int nwords = 0;
    struct WordInfo words[MAXWORDS] = { { "", 0 } };

    char buffer[MAX_WORD_LEN];
    while (fscanf(fp, "%s", buffer) != EOF) {
        int found = 0;
        // Convert to lowercase
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        // Remove trailing punctuation
        char *end = buffer + strlen(buffer) - 1;
        while (end >= buffer && ispunct(*end)) {
            *end-- = 0;
        }
        
        // Check if word already exists
        for (int i = 0; i < nwords; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        // Add new word
        if (!found) {
            if (nwords == MAXWORDS) {
                printf("Too many words (max %d)\n", MAXWORDS);
                return 1;
            }
            strcpy(words[nwords].word, buffer);
            words[nwords].count = 1;
            nwords++;
        }
    }

    // Sort words by count in descending order
    qsort(words, nwords, sizeof(struct WordInfo), cmpfunc);

    // Print frequency table
    printf("%-20s %s\n", "Word", "Frequency");
    printf("--------------------------------\n");
    for (int i = 0; i < nwords; i++) {
        printf("%-20s %d\n", words[i].word, words[i].count);
    }

    fclose(fp);

    return 0;
}