//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTIMENT_THRESHOLD 0.5  // Threshold for sentiment analysis

// Define a structure to hold word and its sentiment value
typedef struct word_sentiment {
    char word[50];
    double sentiment_value;
} WordSentiment;

// Define a function to calculate the sentiment value of a string
double calculate_sentiment(char* str, WordSentiment word_list[], int word_count) {
    double sentiment_sum = 0;
    char delimeter[] = " ,.;:!?-\n\t";  // Delimeter to split words
    char* current_word = strtok(str, delimeter);

    while (current_word != NULL) {  // While there are still words in the string
        for (int i = 0; i < word_count; i++) {  // For each word in the word list
            if (strcmp(current_word, word_list[i].word) == 0) {  // If the words match
                sentiment_sum += word_list[i].sentiment_value;  // Add the sentiment value to the total sum
                break;
            }
        }
        current_word = strtok(NULL, delimeter);  // Move on to the next word
    }

    double sentiment_value = sentiment_sum / word_count;  // Calculate overall sentiment value
    return sentiment_value;
}

int main() {
    WordSentiment word_list[5];  // Word list with sentiment scores
    word_list[0] = (WordSentiment){"happy", 0.8};
    word_list[1] = (WordSentiment){"sad", -0.6};
    word_list[2] = (WordSentiment){"excited", 0.7};
    word_list[3] = (WordSentiment){"angry", -0.5};
    word_list[4] = (WordSentiment){"love", 0.9};

    char input_string[1000];  // Input string to be analyzed
    printf("Enter a statement: ");
    fgets(input_string, 1000, stdin);  // Read input string from user

    double sentiment_value = calculate_sentiment(input_string, word_list, 5);  // Calculate sentiment value

    printf("Sentiment score: %f\n", sentiment_value);
    if (sentiment_value >= SENTIMENT_THRESHOLD) {  // If sentiment is positive
        printf("Positive sentiment detected!\n");
    } else {  // If sentiment is negative
        printf("Negative sentiment detected.\n");
    }

    return 0;
}