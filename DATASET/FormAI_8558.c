//FormAI DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int countWords(char *text, int *wordCount);
void printWordCount(int *wordCount);

int main() {
    char text[MAX_WORDS];
    int wordCount[MAX_WORD_LENGTH] = {0};
    int totalWords;

    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    totalWords = countWords(text, wordCount);
    printf("\nTotal words: %d\n", totalWords);

    printWordCount(wordCount);

    return 0;
}

int countWords(char *text, int *wordCount) {
    int i, j, k;
    int words = 0;
    int wordLength = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]) || text[i] == '-') {
            if (wordLength == 0 && isalpha(text[i])) {
                words++;
            }
            wordLength++;
            if (wordLength > MAX_WORD_LENGTH) {
                wordLength = MAX_WORD_LENGTH;
            }
        } else {
            if (wordLength > 0) {
                wordCount[wordLength - 1]++;
            }
            wordLength = 0;
        }
    }
    
    if (wordLength > 0) {
        wordCount[wordLength - 1]++;
    }
    
    return words;
}

void printWordCount(int *wordCount) {
    int i, j;
    
    printf("Word count:\n");
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (wordCount[i] > 0) {
            if (i == 0) {
                printf("1 letter words: ");
            } else {
                printf("%d letter words: ", i + 1);
            }
            for (j = 0; j < wordCount[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}