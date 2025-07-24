//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
// 'Tis a program for counting the frequency of words,
// In the play of Romeo and fair Juliet, where love birds
// did meet and fall deeply in love, despite the feud
// of Capulets and Montagues in fair Verona, so crude.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

void str_tolower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    FILE *fp;
    char line[1000];
    char *word;
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_NUM_WORDS] = {0};
    int i, j, n;

    fp = fopen("romeo_and_juliet.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    n = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        word = strtok(line, " ,.-\n");
        while (word != NULL) {
            str_tolower(word);
            strcpy(words[n], word);
            freq[n] = 1;
            n++;
            word = strtok(NULL, " ,.-\n");
        }
    }

    fclose(fp);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
                freq[j] = 0;
            }
        }
    }

    printf("Word Frequency Count\n");
    printf("---------------------\n");
    for (i = 0; i < n; i++) {
        if (freq[i] != 0) {
            printf("%-15s\t%d\n", words[i], freq[i]);
        }
    }

    return 0;
}