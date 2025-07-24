//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Define two arrays to hold positive and negative words
char *posWords[10] = {"good", "great", "excellent", "fantastic", "amazing", "love", "happy", "excited", "joyful", "wonderful"};
char *negWords[10] = {"bad", "horrible", "terrible", "awful", "dislike", "hate", "sad", "angry", "frustrated", "unhappy"};

// Function to count the occurrence of a word in the input string
int countWord(char *input, char *word) {
    int count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

// Main function to perform sentiment analysis
int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    int posCount = 0;
    int negCount = 0;

    // Loop through positive words array and count occurrences in input
    for (int i = 0; i < 10; i++) {
        posCount += countWord(input, posWords[i]);
    }

    // Loop through negative words array and count occurrences in input
    for (int i = 0; i < 10; i++) {
        negCount += countWord(input, negWords[i]);
    }

    // Calculate sentiment score based on difference between positive and negative counts
    int score = posCount - negCount;

    // Print sentiment analysis result
    if (score > 0) {
        printf("Sentiment score: %d (Positive)\n", score);
    } else if (score < 0) {
        printf("Sentiment score: %d (Negative)\n", score);
    } else {
        printf("Sentiment score: %d (Neutral)\n", score);
    }

    return 0;
}