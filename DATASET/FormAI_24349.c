//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000

// function to extract individual words from the sentence
int extractWords(char sentence[MAX_SENTENCE_LENGTH], char words[][MAX_SENTENCE_LENGTH])
{
    char* word = strtok(sentence, " ,.?");
    int count = 0;
    while (word != NULL) {
        strcpy(words[count], word);
        ++count;
        word = strtok(NULL, " ,.?");
    }
    return count;
}

// function to determine the sentiment score of a sentence
int getSentimentScore(char sentence[MAX_SENTENCE_LENGTH], char positive[][MAX_SENTENCE_LENGTH], int pCount, char negative[][MAX_SENTENCE_LENGTH], int nCount)
{
    char words[100][MAX_SENTENCE_LENGTH];
    int count = extractWords(sentence, words);
    int score = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < pCount; ++j) {
            if (strcmp(words[i], positive[j]) == 0) {
                ++score;
            }
        }
        for (int j = 0; j < nCount; ++j) {
            if (strcmp(words[i], negative[j]) == 0) {
                --score;
            }
        }
    }
    return score;
}

// program entry point
int main()
{
    char positiveWords[][MAX_SENTENCE_LENGTH] = {"good", "great", "excellent", "fantastic", "wonderful"};
    char negativeWords[][MAX_SENTENCE_LENGTH] = {"bad", "terrible", "awful", "poor", "mediocre"};
    int pCount = 5;
    int nCount = 5;
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int score = getSentimentScore(sentence, positiveWords, pCount, negativeWords, nCount);
    printf("Sentiment Score: %d\n", score);
    return 0;
}