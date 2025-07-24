//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void countWords(char *inputString);

int main() {
    char inputString[MAX_WORDS];
    printf("Enter a sentence to count the frequency of words: \n");
    fgets(inputString, MAX_WORDS, stdin);
    countWords(inputString);
    return 0;
}

void countWords(char *inputString) {
    int wordCount = 0, i, j;
    char wordList[MAX_WORDS][MAX_WORD_LENGTH], tempWord[MAX_WORD_LENGTH];

    for(i=0; i<strlen(inputString); i++) {
        if (isalnum(inputString[i])) { 
        // Skip all non-alphanumeric characters.
            j = 0;
            while(isalnum(inputString[i])) {
                tempWord[j++] = inputString[i++];
            }
            tempWord[j] = '\0';
            int found = 0;
            for(j=0; j<wordCount; j++) {
                if(strcmp(wordList[j], tempWord) == 0) {
                    found = 1;
                    break;
                }
            }
            if(!found) {
                strcpy(wordList[wordCount++], tempWord);
            }
        }
    }

    int countList[wordCount];
    memset(countList, 0, wordCount*sizeof(int));

    for(i=0; i<wordCount; i++) {
        for(j=0; j<strlen(inputString); j++) {
            char temp[MAX_WORD_LENGTH];
            if(isalnum(inputString[j])) {
                int k = 0;
                while(isalnum(inputString[j])) {
                    temp[k++] = inputString[j++];
                }
                temp[k] = '\0';
                if(strcmp(temp, wordList[i]) == 0) {
                    countList[i]++;
                }
            }
        }
    }

    printf("\nWord Count\tWord\n");
    for(i=0; i<wordCount; i++) {
        printf("%d\t\t%s\n", countList[i], wordList[i]);
    }
}