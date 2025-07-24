//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 1000

// Recursive function to calculate sentiment score
int calculateSentimentScore(char *ptr) {
    int sentimentScore = 0; // Initialize sentiment score to 0

    // Base case:
    if (*ptr == '\0') {
        return sentimentScore;
    }

    char temp[MAX_CHARACTERS];
    int i = 0;

    // Ignore punctuation and numbers
    if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
        // Copy current word to temp array
        while (*ptr != ' ' && *ptr != '\0') {
            temp[i++] = *ptr++;
        }

        // Add sentiment score based on word
        if (strcmp(temp, "good") == 0 || strcmp(temp, "great") == 0) {
            sentimentScore += 2;
        } else if (strcmp(temp, "bad") == 0 || strcmp(temp, "terrible") == 0) {
            sentimentScore -= 2;
        } else if (strcmp(temp, "not") == 0) {
            return -1 * calculateSentimentScore(++ptr); // Negate sentiment score
        }
    }

    // Recursive case:
    return sentimentScore + calculateSentimentScore(++ptr);
}

// Driver code to test function
int main() {
    char input[MAX_CHARACTERS];

    printf("Enter a sentence: ");
    fgets(input, MAX_CHARACTERS, stdin);

    int sentimentScore = calculateSentimentScore(input);

    if (sentimentScore > 0) {
        printf("Positive sentiment with score %d\n", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("Negative sentiment with score %d\n", sentimentScore);
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}