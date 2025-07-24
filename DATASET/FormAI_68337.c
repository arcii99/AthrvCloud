//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void performSentimentAnalysis(char *inputText);

int main()
{
    char inputText[500];
    printf("Please enter a sentence or paragraph to analyze: ");
    fgets(inputText, 500, stdin);
    performSentimentAnalysis(inputText);
    return 0;
}

void performSentimentAnalysis(char *inputText) {
    // Shape-shifting variables
    int totalWords = 0, totalPositive = 0, totalNegative = 0, totalNeutral = 0;
    char * currentWord;
    char * currentChar;
    char goodWords[10][20] = {"good", "great", "excellent", "fantastic", "amazing", "wonderful", "terrific", "awesome", "superb", "outstanding"};
    char badWords[10][20] = {"bad", "terrible", "horrible", "awful", "poor", "mediocre", "disappointing", "lousy", "miserable", "not good"};

    // Shape-shifting code
    currentWord = strtok(inputText, " ");
    while (currentWord != NULL) {
        totalWords++;

        // Shape-shift into analyzing each word
        currentChar = strtok(currentWord, "\n!.?(),");

        while (currentChar != NULL) {
            for (int i = 0; i < 10; i++) {
                if (strcmp(currentChar, goodWords[i]) == 0) {
                    totalPositive++;
                } else if (strcmp(currentChar, badWords[i]) == 0) {
                    totalNegative++;
                }
            }
            currentChar = strtok(NULL, "\n!.?(),");

            // Shape-shift to determine neutrality
            if (totalPositive == totalNegative) {
                totalNeutral++;
            }
        }

        // Shape-shift to analyze next word
        currentWord = strtok(NULL, " ");
    }

    // Shape-shift to display results
    printf("\nTotal words analyzed: %d\n", totalWords);
    printf("Total positive words found: %d\n", totalPositive);
    printf("Total negative words found: %d\n", totalNegative);
    printf("Total neutral words found: %d\n", totalNeutral);
}