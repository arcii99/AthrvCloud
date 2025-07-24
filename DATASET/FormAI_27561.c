//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate sentiment score of the given sentence
int calculateSentimentScore(char sentence[]) {
    int score = 0;
    char *words = strtok(sentence, " "); // tokenize sentence based on space delimiter

    while (words != NULL) {
        if (strcmp(words, "good") == 0 || strcmp(words, "great") == 0 || strcmp(words, "excellent") == 0)
            score += 2; // add 2 if word is positive
        else if (strcmp(words, "bad") == 0 || strcmp(words, "horrible") == 0 || strcmp(words, "terrible") == 0)
            score -= 2; // deduct 2 if word is negative
        else
            score += 1; // add 1 for neutral words
        words = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char sentence[100];
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // read input sentence from user
    int score = calculateSentimentScore(sentence); // calculate sentiment score of the given sentence
    printf("Sentiment score of the given sentence is %d\n", score);
    if (score > 0)
        printf("Overall Sentiment is Positive\n");
    else if (score < 0)
        printf("Overall Sentiment is Negative\n");
    else
        printf("Overall Sentiment is Neutral\n");
    return 0;
}