//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SENTENCES 10
#define MAX_SENT_LENGTH 100
#define MAX_WORD_LENGTH 20
#define MAX_COMMON_WORDS 50

void removePunctuation(char *);
int isCommonWord(char *);
void addToCommonWords(char *);
int countCommonWords(char *);
void removeCommonWords(char *);
int getNextSentence(char *, int, char **);
void addSentence(char *, int, char **, int *);
void printSummary(char **, int);

char commonWords[MAX_COMMON_WORDS][MAX_WORD_LENGTH];
int commonWordCount = 0;

int main(int argc, char **argv) {
    char text[1000] = "Machine learning is becoming an increasingly important part of the tech industry. It is also becoming more accessible to people who are not experts in the field. There are a number of online courses and tutorials that can help anyone learn the basics of machine learning. One of the best ways to get started with machine learning is to learn how to use a programming language like Python or R. These languages have libraries that make it easy to get started with machine learning.";

    char *sentences[MAX_SENTENCES];
    int sentenceCount = 0;

    removePunctuation(text);

    int length = strlen(text);
    int start = 0;

    while (start < length) {
        char *sentence = (char *)malloc(MAX_SENT_LENGTH*sizeof(char));
        int sentenceLength = getNextSentence(text, start, &sentence);
        start += sentenceLength + 1;
        addSentence(sentence, sentenceLength, sentences, &sentenceCount);
    }

    for (int i = 0; i < sentenceCount; i++) {
        removeCommonWords(sentences[i]);
    }
    
    printSummary(sentences, sentenceCount);

    return 0;
}

void removePunctuation(char *text) {
    int length = strlen(text);

    for (int i = 0; i < length; i++) {
        if (ispunct(text[i])) {
            text[i] = ' ';
        }
    }
}

int isCommonWord(char *word) {
    for (int i = 0; i < commonWordCount; i++) {
        if (strcmp(word, commonWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void addToCommonWords(char *word) {
    if (commonWordCount == MAX_COMMON_WORDS) {
        return;
    }

    strcpy(commonWords[commonWordCount], word);
    commonWordCount++;
}

int countCommonWords(char *sentence) {
    int count = 0;
    char *word = strtok(sentence, " ");

    while (word != NULL) {
        if (isCommonWord(word)) {
            count++;
        }

        word = strtok(NULL, " ");
    }

    return count;
}

void removeCommonWords(char *sentence) {
    int length = strlen(sentence);
    char *temp = (char *)malloc(length*sizeof(char));
    int index = 0;
    int isSpace = 0;

    for (int i = 0; i <= length; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            temp[index] = '\0';
            index++;

            if (!isCommonWord(temp)) {
                printf("%s ", temp);
            }

            isSpace = 1;
            continue;
        }

        if (isSpace) {
            isSpace = 0;
            temp[0] = sentence[i];
            index = 1;
        } else {
            temp[index] = sentence[i];
            index++;
        }
    }

    printf("\n");
}

int getNextSentence(char *text, int start, char **sentence) {
    int length = strlen(text);
    int end = start;
    int count = 0;

    while (count < MAX_SENT_LENGTH && end < length && text[end] != '.') {
        count++;
        end++;
    }

    strncpy(*sentence, text + start, count);
    (*sentence)[count] = '\0';

    return count;
}

void addSentence(char *sentence, int sentenceLength, char **sentences, int *sentenceCount) {
    if (*sentenceCount == MAX_SENTENCES) {
        return;
    }

    sentences[*sentenceCount] = (char *)malloc((sentenceLength + 1)*sizeof(char));
    strcpy(sentences[*sentenceCount], sentence);
    (*sentenceCount)++;
}

void printSummary(char **sentences, int sentenceCount) {
    int maxScore = 0;
    char *bestSentence;

    for (int i = 0; i < sentenceCount; i++) {
        int score = countCommonWords(sentences[i]);

        if (score > maxScore) {
            maxScore = score;
            bestSentence = sentences[i];
        }
    }

    printf("%s\n", bestSentence);
}