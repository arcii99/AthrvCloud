//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1000

typedef struct words {
    char *word;
    int count;
} Words;


int main(int argc, char *argv[]) {
    char *filename = NULL, *ptr = NULL, *word;
    FILE *fp;
    int i, len, count;
    Words **wordList = NULL;
    int numWords = 0, index;

    if(argc < 2) {
        printf("Usage: ./frequencyCounter <filename>\n");
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 2;
    }

    wordList = (Words **)calloc(10000, sizeof(Words *));

    if(wordList == NULL) {
        printf("Error: Could not allocate memory\n");
        return 3;
    }

    word = (char *)calloc(MAX_WORD_LEN, sizeof(char));

    if(word == NULL) {
        printf("Error: Could not allocate memory\n");
        return 4;
    }

    while(fscanf(fp, "%s", word) != EOF) {
        len = strlen(word);
        ptr = word;
        count = 0;

        for(i=0; i<len; i++) {
            if(isalpha(*ptr)) {
                *ptr = tolower(*ptr);
            } else {
                *ptr = '\0';
            }

            ptr++;
        }

        if(word[0] != '\0') {
            index = -1;

            for(i=0; i<numWords; i++) {
                if(strcmp(word, wordList[i]->word) == 0) {
                    index = i;
                    break;
                }
            }

            if(index == -1) {
                wordList[numWords] = (Words *)calloc(1, sizeof(Words));
                wordList[numWords]->word = strdup(word);
                wordList[numWords]->count = 1;
                numWords++;
            } else {
                wordList[index]->count++;
            }
        }
    }

    printf("Words\tCount\n");

    for(i=0; i<numWords; i++) {
        printf("%s\t%d\n", wordList[i]->word, wordList[i]->count);
    }

    for(i=0; i<numWords; i++) {
        free(wordList[i]->word);
        free(wordList[i]);
    }

    free(wordList);
    free(word);

    fclose(fp);
    return 0;
}