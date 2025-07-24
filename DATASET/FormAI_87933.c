//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove punctuation from a string
void removePunctuation(char *sentence)
{
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        if (ispunct(sentence[i])) {
            memmove(&sentence[i], &sentence[i + 1], len - i);
            len--;
            i--;
        }
    }
}

// Function to count the number of occurrences of a word in a sentence
int countOccurrences(char *sentence, char *word)
{
    int count = 0;
    char *token;
    char *phrase = strdup(sentence); // Make a copy of the original sentence
    token = strtok(phrase, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    free(phrase); // Free the dynamically allocated memory
    return count;
}

int main()
{
    // Initialize input sentence and list of positive and negative words
    char sentence[1000];
    char *positiveWords[10] = {"good", "great", "excellent", "fantastic", "awesome", "nice", "happy", "love", "wonderful", "amazing"};
    char *negativeWords[10] = {"bad", "terrible", "awful", "horrible", "poor", "unhappy", "hate", "dislike", "disgusting", "miserable"};

    // Ask user for input sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove punctuation from input sentence
    removePunctuation(sentence);

    // Convert input sentence to lowercase
    char *lowercase = sentence;
    for (int i = 0; i <= strlen(lowercase); i++) {
        lowercase[i] = tolower(lowercase[i]);
    }

    // Calculate sentiment score
    int positiveScore = 0;
    int negativeScore = 0;
    for (int i = 0; i < 10; i++) {
        positiveScore += countOccurrences(lowercase, positiveWords[i]);
        negativeScore += countOccurrences(lowercase, negativeWords[i]);
    }
    int sentimentScore = (positiveScore - negativeScore);

    // Determine sentiment of input sentence
    if (sentimentScore > 0) {
        printf("Positive sentiment!\n");
    } else if (sentimentScore < 0) {
        printf("Negative sentiment :(\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    return 0;
}