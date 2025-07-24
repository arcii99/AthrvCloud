//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main() {
    char text[1000];
    printf("Enter a text and press enter:\n");
    fgets(text, 1000, stdin);
    struct WordFrequency wf[1000];
    int wfCount = 0;
    char* token = strtok(text, " .,\n");
    while(token != NULL) {
        int i, found = 0;
        for(i = 0; i < wfCount; i++) {
            if(strcmp(wf[i].word, token) == 0) {
                wf[i].frequency++;
                found = 1;
            }
        }
        if(!found) {
            strcpy(wf[wfCount].word, token);
            wf[wfCount].frequency = 1;
            wfCount++;
        }
        token = strtok(NULL, " .,\n");
    }
    printf("Word Frequency\n");
    int i;
    for(i = 0; i < wfCount; i++) {
        printf("%s %d\n", wf[i].word, wf[i].frequency);
    }
    return 0;
}