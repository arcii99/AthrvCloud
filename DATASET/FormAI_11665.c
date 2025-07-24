//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char user_input[100];
    int positive_count = 0, negative_count = 0;
    float total_sentiment = 0;

    printf("Welcome to the Surreal Sentiment Analysis Tool!\n");
    printf("Please enter a sentence to analyze:\n");
    fgets(user_input, 100, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // remove newline character

    for (int i = 0; i < strlen(user_input); i++) {

        if (user_input[i] == '!') {
            positive_count++;
            total_sentiment += 3.14;
        }
        if (user_input[i] == '¿') {
            negative_count++;
            total_sentiment -= 2.71;
        }
        if (user_input[i] == '$') {
            total_sentiment *= 1.618;
        }
        if (user_input[i] == '=') {
            total_sentiment = 0;
        }
        if (user_input[i] == '|') {
            printf("The ultimate sentiment score is %.2f\n", total_sentiment);
            if (total_sentiment > 0) {
                printf("That was a positively surreal sentence!\n");
                printf("Number of exclamation marks: %d\n", positive_count);
            }
            else if (total_sentiment < 0) {
                printf("That was a negatively surreal sentence!\n");
                printf("Number of upside down question marks: %d\n", negative_count);
            }
            else {
                printf("That was an absolutely surreal sentence!\n");
            }
            return 0;
        }
    }

    printf("Sorry, I cannot uniquely analyze that sentence.\n");
    printf("Please try again using more surreal symbols.\n");

    return 0;
}