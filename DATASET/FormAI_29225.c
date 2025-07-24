//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

int main() {
    char text[1000]; // array to store input text
    int wordCount = 0; // count of words
    int positiveCount = 0; // count of positive words
    int negativeCount = 0; // count of negative words

    // list of positive and negative words
    char positiveWords[10][20] = {"happy", "joy", "great", "excellent", "fantastic", "love", "awesome", "amazing", "best", "wonderful"};
    char negativeWords[10][20] = {"sad", "hate", "bad", "poor", "terrible", "worst", "dislike", "awful", "horrible", "unhappy"};

    // get text input from user
    printf("Enter text to analyze: ");
    fgets(text, 1000, stdin);

    // loop through words in text
    char *word = strtok(text, " ");
    while (word != NULL) {
        // remove newline character from end of word
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }

        // check if word is positive or negative
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                positiveCount++;
            }
            if (strcmp(word, negativeWords[i]) == 0) {
                negativeCount++;
            }
        }

        // increment word count
        wordCount++;

        // get next word
        word = strtok(NULL, " ");
    }

    // calculate sentiment score
    double sentimentScore = ((double) positiveCount - (double) negativeCount) / (double) wordCount;

    // print sentiment analysis results
    printf("\nSentiment Analysis Results:\n");
    printf("Total words analyzed: %d\n", wordCount);
    printf("Positive words: %d\n", positiveCount);
    printf("Negative words: %d\n", negativeCount);

    // determine sentiment score classification
    if (sentimentScore > 0.5) {
        printf("Sentiment score: %f (very positive)\n", sentimentScore);
    } else if (sentimentScore > 0) {
        printf("Sentiment score: %f (positive)\n", sentimentScore);
    } else if (sentimentScore == 0) {
        printf("Sentiment score: %f (neutral)\n", sentimentScore);
    } else if (sentimentScore > -0.5) {
        printf("Sentiment score: %f (negative)\n", sentimentScore);
    } else {
        printf("Sentiment score: %f (very negative)\n", sentimentScore);
    }

    return 0;
}