//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {

    // Define the input text string
    char text[100] = "This is a great tool, I really like it!";
    
    // Define positive and negative words array
    char positiveWords[][20] = {"great","like","fantastic","awesome","good"};
    char negativeWords[][20] = {"bad","awful","terrible","hate","dislike"};

    // Split the input text into individual words
    char *word = strtok(text, " ,.!?");
    
    // Initialize the sentiment score count
    int sentimentScore = 0;

    // Loop through each word in the input text
    while (word != NULL) {

        // Check if the word is a positive word or not
        for (int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                sentimentScore++;
                break;
            }
        }

        // Check if the word is a negative word or not
        for (int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++) {
            if (strcmp(word, negativeWords[i]) == 0) {
                sentimentScore--;
                break;
            }
        }

        // Move to the next word in the input text
        word = strtok(NULL, " ,.!?");
    }

    // Print the sentiment score of the input text
    if (sentimentScore > 0) {
        printf("The sentiment score of the input text is %d, which indicates a positive sentiment.", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("The sentiment score of the input text is %d, which indicates a negative sentiment.", sentimentScore);
    } else {
        printf("The sentiment score of the input text is %d, which indicates a neutral sentiment.", sentimentScore);
    }

    return 0;
}