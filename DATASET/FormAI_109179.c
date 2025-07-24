//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000 // Maximum supported input string length
#define POSITIVE_THRESHOLD 0.7 // Threshold value to classify a sentence as positive
#define NEGATIVE_THRESHOLD 0.3 // Threshold value to classify a sentence as negative

// Function to count the number of occurrences of a substring within a string
int countOccurrences(char *sentence, char *word) {
    int count = 0;
    char *temp = sentence;

    while ((temp = strstr(temp, word)) != NULL) {
        count++;
        temp += strlen(word);
    }

    return count;
}

// Function to remove punctuation marks from a string
void removePunctuations(char *string) {
    int len = strlen(string);

    for (int i = 0; i < len; i++) {
        if (ispunct(string[i])) {
            for (int j = i; j < len - 1; j++) {
                string[j] = string[j+1];
            }

            len--;
            i--;
        }
    }
}

int main() {
    char inputString[MAX_STRING_LENGTH] = "";
    printf("Enter a sentence for sentiment analysis: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    // Pre-processing the input string
    removePunctuations(inputString);

    // Splitting the input string into words
    char *word = strtok(inputString, " \n");
    int positiveWordsCount = 0;
    int negativeWordsCount = 0;
    int totalWordsCount = 0;

    // Looping through each word in the input string and counting the number of positive and negative words
    while (word != NULL) {
        totalWordsCount++;

        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            positiveWordsCount++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "poor") == 0 || strcmp(word, "worst") == 0) {
            negativeWordsCount++;
        }

        word = strtok(NULL, " \n");
    }

    // Calculating the sentiment score of the input string
    double positiveSentimentScore = (double)positiveWordsCount / (double)totalWordsCount;
    double negativeSentimentScore = (double)negativeWordsCount / (double)totalWordsCount;

    // Classifying the input string based on the sentiment score
    if (positiveSentimentScore > POSITIVE_THRESHOLD) {
        printf("The input sentence is positively categorized with a score of %f.\n", positiveSentimentScore);
    } else if (negativeSentimentScore > NEGATIVE_THRESHOLD) {
        printf("The input sentence is negatively categorized with a score of %f.\n", negativeSentimentScore);
    } else {
        printf("The input sentence is neutrally categorized.\n");
    }

    return 0;
}