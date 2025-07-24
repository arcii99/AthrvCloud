//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {

    char input[1000]; // declare user input array
    int score = 0; // initialize sentiment score to 0

    // start program with an exciting message!
    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("This program will rate the sentiment of a user's input.\n");
    printf("Let's get started!\n");

    // prompt for user input
    printf("\nEnter your text here: ");
    fgets(input, sizeof(input), stdin); // read user input

    // replace newline char with null char
    input[strcspn(input, "\n")] = 0;

    // split input into individual words
    char *word = strtok(input, " ");

    while (word != NULL) {

        // check for positive words
        if (strcmp(word, "amazing") == 0 || strcmp(word, "awesome") == 0 || strcmp(word, "fantastic") == 0 || strcmp(word, "incredible") == 0 || strcmp(word, "superb") == 0) {
            score += 2; // increment score by 2 for positive words
        }

        // check for negative words
        else if (strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "disgusting") == 0 || strcmp(word, "pathetic") == 0) {
            score -= 2; // decrement score by 2 for negative words
        }

        // check for neutral words
        else if (strcmp(word, "is") == 0 || strcmp(word, "are") == 0 || strcmp(word, "am") == 0 || strcmp(word, "was") == 0 || strcmp(word, "were") == 0) {
            score += 0; // no change in score for neutral words
        }

        // if word is not positive, negative, or neutral, it will be classified as a random word
        else {
            score += 1; // increment score by 1 for random words
        }

        word = strtok(NULL, " "); // move to next word
    }

    // output sentiment score and corresponding message
    printf("\nThe sentiment score for this input is: %d\n", score);

    if (score > 0) {
        printf("Great job! Your input has a positive sentiment.\n");
    }

    else if (score == 0) {
        printf("Your input has a neutral sentiment.\n");
    }

    else {
        printf("Oops! Your input has a negative sentiment.\n");
    }

    return 0; // end program
}