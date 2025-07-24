//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 1000
#define MAX_WORDS 1000

typedef struct WordFrequency {
    char* word;
    int count;
} WordFrequency;

int compare(const void* a, const void* b) {
    WordFrequency* wf1 = (WordFrequency*) a;
    WordFrequency* wf2 = (WordFrequency*) b;
    return wf2->count - wf1->count;
}

int isAlphaNum(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

void toLowercase(char* s) {
    int i = 0;
    while (s[i]) {
        s[i] = tolower(s[i]);
        i++;
    }
}

int main() {
    char text[10000];
    char* words[MAX_WORDS];
    WordFrequency wf[MAX_WORDS];
    int i, j, n = 0;
    
    // read in the text
    printf("Enter some text (max 10000 bytes):\n");
    fgets(text, sizeof(text), stdin);
    
    // split text into words    
    char* token = strtok(text, " \n\t\r,.;:");
    while (token != NULL) {
        toLowercase(token);
        words[n] = (char*) malloc(strlen(token) + 1);
        strcpy(words[n], token);
        n++;
        token = strtok(NULL, " \n\t\r,.;:");
    }
    
    // count the word frequencies    
    int count;
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i+1; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
                free(words[j]);
                words[j] = NULL;
            }
        }
        if (words[i] != NULL) {
            wf[i].word = words[i];
            wf[i].count = count;
        }
        else {
            wf[i].count = 0;
        }
    }
    
    // sort the word frequencies
    qsort(wf, n, sizeof(WordFrequency), compare);
    
    // print the word frequencies    
    printf("Word Frequencies:\n");
    for (i = 0; i < n; i++) {
        if (wf[i].count == 0) break;
        printf("%-20s %d\n", wf[i].word, wf[i].count);
    }

    return 0;
}