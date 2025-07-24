//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50000
#define MAX_SUMMARY_LENGTH 100
#define MAX_SENTENCE_LENGTH 200

int main() {
    char input[MAX_INPUT_LENGTH] = { 0 };
    char summary[MAX_SUMMARY_LENGTH] = { 0 };
    int sentenceCount = 0;
    int currentIndex = 0;
    int currentScore = 0;
    int summaryIndex = 0;
    int totalScore = 0;

    printf("Welcome to the Happy Summarizer!\n");
    printf("Please enter your text:\n");

    // read input from the user
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // count number of sentences
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentenceCount++;
        }
    }

    // calculate score for each sentence and find the highest scoring sentence
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            currentScore = 0;
            for (int j = currentIndex; j < i; j++) {
                if (input[j] == 'g' || input[j] == 'h' || input[j] == 'a' || input[j] == 'p' || input[j] == 'y') {
                    currentScore++;
                } else if (input[j] == 's' || input[j] == 'a' || input[j] == 'd') {
                    currentScore--;
                }
            }
            if (currentScore > totalScore) {
                totalScore = currentScore;
                summaryIndex = currentIndex;
            }
            currentIndex = i + 1;
        }
    }

    // create the summary by selecting the highest scoring sentence and the following two sentences
    for (int i = summaryIndex; i < strlen(input); i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            if (summaryIndex != i && sentenceCount > 3) {
                if ((i - summaryIndex) > MAX_SENTENCE_LENGTH) {
                    i++;
                    continue;
                }
                strncat(summary, &input[summaryIndex], (i - summaryIndex));
                strncat(summary, ".", 1);
                summaryIndex = i + 1;
                sentenceCount--;
                if (sentenceCount == 0 || strlen(summary) >= MAX_SUMMARY_LENGTH) {
                    break;
                }
            }
        }
    }

    printf("Your summary is:\n");
    printf("%s\n", summary);

    return 0;
}