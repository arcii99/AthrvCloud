//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int compare_wordcounts(const void *a, const void *b) {
    WordCount *wa = (WordCount *) a;
    WordCount *wb = (WordCount *) b;

    if (wa->count != wb->count) {
        return wb->count - wa->count; // descending order
    } else {
        return strcmp(wa->word, wb->word); // alphabetical order
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Cannot open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // Word counting
    WordCount wordcounts[100000];
    int num_wordcounts = 0;

    char word[MAX_WORD_LENGTH + 1] = "";
    int len = 0;
    int c = fgetc(file);

    while (c != EOF) {
        if (isalpha(c)) {
            if (len < MAX_WORD_LENGTH) {
                word[len++] = tolower(c);
            }
        } else {
            if (len > 0) {
                word[len] = '\0';

                int i;
                for (i = 0; i < num_wordcounts; i++) {
                    if (strcmp(word, wordcounts[i].word) == 0) {
                        wordcounts[i].count++;
                        break;
                    }
                }

                if (i == num_wordcounts) {
                    WordCount wc;
                    strcpy(wc.word, word);
                    wc.count = 1;

                    wordcounts[num_wordcounts++] = wc;
                }

                len = 0;
                memset(word, 0, sizeof(word));
            }
        }

        c = fgetc(file);
    }

    fclose(file);

    // Sorting
    qsort(wordcounts, num_wordcounts, sizeof(WordCount), compare_wordcounts);

    // Output
    int i;
    for (i = 0; i < num_wordcounts; i++) {
        printf("%s: %d\n", wordcounts[i].word, wordcounts[i].count);
    }

    printf("Total words: %d", num_wordcounts);

    return EXIT_SUCCESS;
}