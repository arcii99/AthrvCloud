//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Function to analyze the sentiment of a given sentence
void analyzeSentiment(char sentence[]) {
    int positiveCount = 0, negativeCount = 0;

    // List of positive and negative words
    char positiveWords[10][20] = {"good", "great", "excellent", "satisfied", "happy", "pleased", "wonderful", "fantastic", "delightful", "terrific"};
    char negativeWords[10][20] = {"bad", "terrible", "awful", "poor", "difficult", "disappointed", "displeased", "horrible", "pathetic", "worst"};

    // Tokenize the sentence into words
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        // Check if the word is in the list of positive or negative words
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                positiveCount++;
            } else if (strcmp(word, negativeWords[i]) == 0) {
                negativeCount++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Determine the overall sentiment of the sentence
    if (positiveCount > negativeCount) {
        printf("Sentiment: Positive\n");
    } else if (negativeCount > positiveCount) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
}

int main() {
    char sentence[1000];

    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Remove the newline character from the end of the sentence
    sentence[strcspn(sentence, "\n")] = 0;

    // Analyze the sentiment of the sentence
    analyzeSentiment(sentence);

    return 0;
}