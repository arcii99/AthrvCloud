//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the sentiment score of a sentence
int calculate_score(char sentence[]) {
    // Initializing sentiment score to 0
    int score = 0;

    // Array of positive words
    char positive[][20] = {"good", "great", "awesome", "amazing", "excellent"};

    // Array of negative words
    char negative[][20] = {"bad", "awful", "terrible", "horrible", "poor"};

    // Tokenizing the sentence
    char *word = strtok(sentence, " ");

    while (word != NULL) {
        // Checking if the word is positive or negative
        for (int i=0; i<5; i++) {
            if (strcmp(word, positive[i]) == 0) {
                score += 1;
            }
            if (strcmp(word, negative[i]) == 0) {
                score -= 1;
            }
        }
        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    char sentence[100];

    // Getting input from user
    printf("Enter a sentence: ");
    scanf("%[^\n]%*c", sentence);

    // Calculating sentiment score
    int score = calculate_score(sentence);

    // Displaying sentiment score
    printf("Sentiment score = %d", score);

    return 0;
}