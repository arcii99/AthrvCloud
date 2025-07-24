//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
    WordCount *wordCount1 = (WordCount *) a;
    WordCount *wordCount2 = (WordCount *) b;
    return wordCount2->frequency - wordCount1->frequency;
}

void stripChars(char *str, char *chars) {
    int i, j;
    for (i = j = 0; str[i]; i++)
        if (!strchr(chars, str[i]))
            str[j++] = str[i];
    str[j] = '\0';
}

int main() {
    char c, word[MAX_WORD_LENGTH];
    int i = 0, j, numWords = 0, found;
    WordCount wordCounts[MAX_WORDS];
    FILE *fptr;

    fptr = fopen("inputFile.txt", "r");
    if (fptr == NULL) {
        printf("Could not open file.\n");
        return -1;
    }

    while ((c = fgetc(fptr)) != EOF) {
        if (isalpha(c) || c == '\'') {
            if (i < MAX_WORD_LENGTH)
                word[i++] = tolower(c);
        } else if (i > 0) {
            word[i] = '\0';
            found = 0;
            for (j = 0; j < numWords; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].frequency = 1;
                numWords++;
            }
            i = 0;
        }
    }

    fclose(fptr);

    char charsToRemove[] = {'.', ',', ';', '!', '?', ':', '\"', ')', '('};
    for (i = 0; i < numWords; i++)
        stripChars(wordCounts[i].word, charsToRemove);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    printf("%-15s %s\n", "Word", "Frequency");
    printf("=================================\n");
    for (i = 0; i < numWords; i++)
        printf("%-15s %d\n", wordCounts[i].word, wordCounts[i].frequency);

    return 0;
}