//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void analyze_sentiment(char *input, char *positive_words[][2], char *negative_words[][2], int positive_count, int negative_count) {
    int total_positive = 0;
    int total_negative = 0;
    char *word;
    word = strtok(input, " "); // Splitting input into words using " " as delimiter
    while (word != NULL) {
        for (int i=0; i<positive_count; i++) {
            if (strcmp(word, positive_words[i][0]) == 0) { // Comparing whether the word is positive or not
                total_positive += atoi(positive_words[i][1]); // Adding the score of the positive word
            }
        }
        for (int i=0; i<negative_count; i++) {
            if (strcmp(word, negative_words[i][0]) == 0) { // Comparing whether the word is negative or not
                total_negative += atoi(negative_words[i][1]); // Adding the score of the negative word
            }
        }
        word = strtok(NULL, " ");
    }
    if (total_positive > total_negative) {
        printf("The sentiment of the input is Positive!\n");
    } else if (total_positive < total_negative) {
        printf("The sentiment of the input is Negative!\n");
    } else {
        printf("The sentiment of the input is Neutral!\n");
    }
}

int main() {
    char *input;
    input = (char *)malloc(1024*sizeof(char));
    printf("Enter your input:\n");
    fgets(input, 1024, stdin); // Getting input from user

    char *positive_words[][2] = {{"happy", "2"}, {"good", "1"}, {"great", "3"}}; // Positive words and their score
    int positive_count = sizeof(positive_words)/sizeof(positive_words[0]);
    
    char *negative_words[][2] = {{"sad", "-2"}, {"bad", "-1"}, {"terrible", "-3"}}; // Negative words and their score
    int negative_count = sizeof(negative_words)/sizeof(negative_words[0]);

    analyze_sentiment(input, positive_words, negative_words, positive_count, negative_count);
    free(input);
    return 0;
}