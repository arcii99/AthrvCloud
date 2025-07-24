//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to calculate sentiment score for a given review
float calculateSentimentScore(char review[]) {
    float sentimentScore = 0.0;
    char word[50];
    int wordIndex = 0;

    // creating a dictionary of positive and negative words
    char positiveDictionary[][20] = {"good", "great", "excellent", "fantastic", "amazing"};
    char negativeDictionary[][20] = {"bad", "poor", "terrible", "awful", "horrible"};

    // iterating over each character in the review
    for(int i=0; review[i]!='\0'; i++) {
        if(!isspace(review[i])) {  // if the character is not a space
            word[wordIndex] = tolower(review[i]);  // covert the character to uppercase and append it to word
            wordIndex++;
        }
        else {  // if the character is a space
            word[wordIndex] = '\0';  // terminate the word
            wordIndex = 0;

            // checking if the word is present in the positive dictionary
            for(int j=0; j<5; j++) {
                if(strcmp(word, positiveDictionary[j]) == 0) {  // if the word is present in the dictionary
                    sentimentScore += 0.5;  // increase the sentiment score by 0.5
                    break;
                }
            }

            // checking if the word is present in the negative dictionary
            for(int j=0; j<5; j++) {
                if(strcmp(word, negativeDictionary[j]) == 0) {  // if the word is present in the dictionary
                    sentimentScore -= 0.5;  // decrease the sentiment score by 0.5
                    break;
                }
            }
        }
    }

    return sentimentScore;
}

int main() {
    char review[1000];

    printf("Enter your review: ");
    fgets(review, 1000, stdin);  // reading the review from user

    float sentimentScore = calculateSentimentScore(review);  // calculating sentiment score for the given review

    printf("\nSentiment Score: %f\n", sentimentScore);

    if(sentimentScore >= 0) {  // if sentiment score is positive
        printf("\nThis is a positive review!\n");
    }
    else {  // if sentiment score is negative
        printf("\nThis is a negative review!\n");
    }

    return 0;
}