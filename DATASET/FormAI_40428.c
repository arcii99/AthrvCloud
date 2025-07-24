//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to analyze the sentiment of the given text
void analyze_sentiment(char *text)
{
    int positive_count = 0, negative_count = 0, neutral_count = 0;
    // List of positive and negative words for comparison
    char *positive_words[] = {"good", "great", "awesome", "fantastic", "excellent", "love", "like", "happy", "amazing"};
    char *negative_words[] = {"bad", "awful", "terrible", "horrible", "dislike", "angry", "hate", "sad", "disappoint"};

    // Tokenize the text into words
    char *word = strtok(text, " \t\n");
    while (word != NULL) {
        // Compare each word with the positive and negative word lists
        for (int i = 0; i < sizeof(positive_words)/sizeof(positive_words[0]); i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            }
        }
        for (int i = 0; i < sizeof(negative_words)/sizeof(negative_words[0]); i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " \t\n");
    }

    // Determine the sentiment based on the count of positive and negative words
    if (positive_count > negative_count) {
        printf("The sentiment of the text is positive.\n");
    } else if (negative_count > positive_count) {
        printf("The sentiment of the text is negative.\n");
    } else {
        printf("The sentiment of the text is neutral.\n");
    }
}

int main()
{
    // Get the user input
    char text[1000];
    printf("Enter some text to analyze the sentiment: ");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character from the end of the string
    text[strcspn(text, "\n")] = 0;

    // Analyze the sentiment
    analyze_sentiment(text);

    return 0;
}