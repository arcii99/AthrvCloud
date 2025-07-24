//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

//Function to check the sentiment of the input string
int check_sentiment(char input[]) {
    int positive_words = 0, negative_words = 0, neutral_words = 0;
    char *token;

    //List of positive and negative words
    char *positive[] = {"good", "excellent", "happy", "love", "success"};
    char *negative[] = {"bad", "terrible", "sad", "hate", "failure"};

    //Tokenizing the input string
    token = strtok(input, " ");
    while(token != NULL) {
        for(int i=0; i<5; i++) {
            if(strcmp(token, positive[i])==0) {
                positive_words++;
            }
            else if(strcmp(token, negative[i])==0) {
                negative_words++;
            }
            else {
                neutral_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    //Checking the sentiment based on word count
    if(positive_words > negative_words && positive_words > neutral_words) {
        return 1;
    }
    else if(negative_words > positive_words && negative_words > neutral_words) {
        return -1;
    }
    else {
        return 0;
    }
}

//Main function
int main() {
    char input[100];
    printf("Enter the sentence to check sentiment: ");
    fgets(input, 100, stdin);

    //Removing the newline character
    input[strcspn(input, "\n")] = 0;

    //Checking the sentiment and displaying the result
    if(check_sentiment(input) == 1) {
        printf("The input sentence is positive.\n");
    }
    else if(check_sentiment(input) == -1) {
        printf("The input sentence is negative.\n");
    }
    else {
        printf("The input sentence is neutral.\n");
    }

    return 0;
}