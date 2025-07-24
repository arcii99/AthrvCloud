//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct WordCount {
    char word[50];
    int count;
} WordCount;

void countWords(FILE *fp, WordCount *wc, int *numWords) {
    char buffer[1000];
    int i = 0, j = 0;
    while (fgets(buffer, 1000, fp)) {
        i = 0;
        while (buffer[i] != '\0') {
            char word[50];
            int count = 0;
            while(isalpha(buffer[i])) {
                word[count++] = buffer[i++];
            }
            if (count > 0) {
                word[count] = '\0';
                int found = 0;
                for (j = 0; j < *numWords; j++) {
                    if (strcmp(wc[j].word, word) == 0) {
                        wc[j].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(wc[*numWords].word, word);
                    wc[*numWords].count++;
                    (*numWords)++;
                }
            }
            i++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file %s\n", filename);
        return 0;
    }
    
    WordCount wc[1000];
    int numWords = 0;

    countWords(fp, wc, &numWords);

    fclose(fp);

    // sort the words by frequency
    int i, j;
    for (i = 0; i < numWords; i++) {
        for (j = i+1; j < numWords; j++) {
            if (wc[j].count > wc[i].count) {
                WordCount temp = wc[i];
                wc[i] = wc[j];
                wc[j] = temp;
            }
        }
    }

    printf("%s\n", "Word Frequencies:");
    printf("%s\n", "-----------------------------");
    for (i = 0; i < numWords; i++) {
        printf("%d: %s - %d\n", i+1, wc[i].word, wc[i].count);
    }

    return 0;
}