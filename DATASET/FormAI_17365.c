//FormAI DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000
#define MAX_SUMMARY_SIZE 1000

// struct to hold each sentence in the input text
typedef struct Sentence {
    char sentence[1000];
    int sentenceRank;
    double sentenceScore;
    struct Sentence *next;
} Sentence;

int numOfSentences = 0;

// function to tokenize the input text into sentences
void tokenizeInput(Sentence *head, char *inputText) {
    char *token = strtok(inputText, ".\n");
    while (token != NULL) {
        Sentence *newSentence = malloc(sizeof(Sentence));
        newSentence->sentenceRank = numOfSentences;
        strncpy(newSentence->sentence, token, sizeof(newSentence->sentence));
        newSentence->next = NULL;
        if (head == NULL) {
            head = newSentence;
        } else {
            Sentence *currentNode = head;
            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            }
            currentNode->next = newSentence;
        }
        numOfSentences++;
        token = strtok(NULL, ".\n");
    }
}

// function to calculate the score of each sentence based on a weighted frequency of its words
void calculateSentenceScore(Sentence *head) {
    double wordFreq[numOfSentences][numOfSentences];
    memset(wordFreq, 0, sizeof(wordFreq));
    Sentence *currentNode = head;
    while (currentNode != NULL) {
        char sentenceCopy[1000];
        strncpy(sentenceCopy, currentNode->sentence, sizeof(sentenceCopy));
        char *token = strtok(sentenceCopy, " ");
        while (token != NULL) {
            wordFreq[currentNode->sentenceRank][currentNode->sentenceRank]++;
            token = strtok(NULL, " ");
        }
        currentNode = currentNode->next;
    }

    for (int i = 0; i < numOfSentences; i++) {
        for (int j = 0; j < numOfSentences; j++) {
            if (i != j) {
                wordFreq[i][j] = 0;
                Sentence *currentNode = head;
                while (currentNode != NULL) {
                    char sentenceCopy[1000];
                    strncpy(sentenceCopy, currentNode->sentence, sizeof(sentenceCopy));
                    char *token = strtok(sentenceCopy, " ");
                    while (token != NULL) {
                        if (strstr(head[i].sentence, token) != NULL) {
                            wordFreq[i][j]++;
                        }
                        token = strtok(NULL, " ");
                    }
                    currentNode = currentNode->next;
                }
            }
        }
    }

    currentNode = head;
    while (currentNode != NULL) {
        double totalScore = 0;
        for (int i = 0; i < numOfSentences; i++) {
            if (i != currentNode->sentenceRank) {
                totalScore += wordFreq[i][currentNode->sentenceRank];
            }
        }
        currentNode->sentenceScore = totalScore;
        currentNode = currentNode->next;
    }
}

// function to create the summary by selecting the highest scored sentences
char *createSummary(Sentence *head, int numOfSentences) {
    int summarySize = 0;
    Sentence *currentNode = head;
    while (currentNode != NULL) {
        summarySize += strlen(currentNode->sentence);
        currentNode = currentNode->next;
    }

    char *summary = malloc(sizeof(char) * MAX_SUMMARY_SIZE);
    memset(summary, '\0', MAX_SUMMARY_SIZE);

    int summaryIndex = 0;
    while (summarySize > 0) {
        double maxScore = -1;
        currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->sentenceScore > maxScore) {
                maxScore = currentNode->sentenceScore;
            }
            currentNode = currentNode->next;
        }
        currentNode = head;
        while (currentNode != NULL) {
            if (currentNode->sentenceScore == maxScore) {
                strcat(summary, currentNode->sentence);
                summaryIndex += strlen(currentNode->sentence);
                currentNode->sentenceScore = -1;
                break;
            }
            currentNode = currentNode->next;
        }
        summary[strlen(summary)] = ' ';
        summaryIndex++;
        summarySize -= strlen(summary);
    }

    return summary;
}

int main() {
    char inputText[MAX_INPUT_SIZE];
    memset(inputText, '\0', MAX_INPUT_SIZE);

    printf("Enter the text to summarize:\n");
    fgets(inputText, MAX_INPUT_SIZE, stdin);

    Sentence *head = NULL;
    tokenizeInput(head, inputText);
    calculateSentenceScore(head);

    char *summary = createSummary(head, numOfSentences);
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}