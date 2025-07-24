//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
/*
Sentiment Analysis Tool Example Program

This program takes in user input and determines if the input has a positive,
negative, or neutral sentiment. It does so by analyzing the words in the input and
checking if they are positive, negative, or neutral words.

Author: [Your Name]

Date: [Date of Creation]
*/

#include <stdio.h>
#include <string.h>

// Define arrays of positive, negative, and neutral words
char* pos_words[] = {"good", "happy", "great", "wonderful", "amazing", "love", "excellent", "fun", "fantastic", "terrific"};
char* neg_words[] = {"bad", "sad", "terrible", "horrible", "awful", "hate", "not", "no", "dislike", "unhappy"};
char* neu_words[] = {"okay", "fine", "alright", "neutral", "indifferent", "average"};

// Define function to check if a word is in a given array
int word_in_array(char* word, char** array, int size) {
    for(int i = 0; i < size; i++) {
        int match = strcmp(word, array[i]);
        if(match == 0) {
            return 1;
        }
    }
    return 0;
}

// Define function to get sentiment of user input
int get_sentiment(char* input) {
    // Tokenize input by spaces
    char* token = strtok(input, " ");
    int pos_count = 0, neg_count = 0, neu_count = 0;
    int has_pos = 0, has_neg = 0, has_neu = 0;
    while(token != NULL) {
        // Check if token is a positive or negative word
        if(word_in_array(token, pos_words, 10)) {
            pos_count++;
            has_pos = 1;
        } else if(word_in_array(token, neg_words, 10)) {
            neg_count++;
            has_neg = 1;
        } else if(word_in_array(token, neu_words, 6)) {
            neu_count++;
            has_neu = 1;
        }
        token = strtok(NULL, " ");
    }

    // Determine sentiment based on word count and presence of positive and negative words
    if(pos_count > neg_count) {
        if(has_neg) {
            return 3; // Mixed sentiment
        } else if(neu_count > 0) {
            return 2; // Mostly positive
        } else {
            return 1; // Very positive
        }
    } else if(neg_count > pos_count) {
        if(has_pos) {
            return 3; // Mixed sentiment
        } else if(neu_count > 0) {
            return 4; // Mostly negative
        } else {
            return 5; // Very negative
        }
    } else {
        if(has_pos && has_neg) {
            return 3; // Mixed sentiment
        } else if(has_neu) {
            return 6; // Neutral sentiment
        } else {
            return 7; // Cannot determine sentiment
        }
    }
}

int main() {
    // Get user input and remove newline character
    printf("Enter a sentence: ");
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    // Get sentiment and output result
    int sentiment = get_sentiment(input);
    printf("Sentiment: ");
    switch(sentiment) {
        case 1:
            printf("Very positive");
            break;
        case 2:
            printf("Mostly positive");
            break;
        case 3:
            printf("Mixed");
            break;
        case 4:
            printf("Mostly negative");
            break;
        case 5:
            printf("Very negative");
            break;
        case 6:
            printf("Neutral");
            break;
        case 7:
            printf("Cannot determine");
            break;
    }
    printf("\n");

    return 0;
}