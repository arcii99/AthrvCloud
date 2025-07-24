//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
// A Sentiment analysis tool in C

#include <stdio.h>
#include <string.h>

// Function prototypes
void analyzeSentiment(char *);
int getScore(char *);

int main() {
    char input[1000]; // Maximum input size

    printf("Welcome to the Sentiment Analysis Tool\n");
    printf("Enter text to analyze sentiment (type 'exit' to quit):\n");

    while (1) {
        fgets(input, 1000, stdin); // Get input from user

        if (strcmp(input, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        analyzeSentiment(input);
    }

    return 0;
}

// Analyze sentiment of input string
void analyzeSentiment(char *input) {
    int score = getScore(input);

    if (score > 0) {
        printf("Sentiment: Positive\n");
    } else if (score < 0) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
}

// Get sentiment score of input string
int getScore(char *input) {
    int score = 0;
    const char *positiveWords[] = {"love", "happy", "great", "awesome", "amazing"};
    const char *negativeWords[] = {"hate", "sad", "terrible", "awful", "bad"};

    // Positive words increment score, negative words decrement score
    char *token = strtok(input, " ");
    while (token != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                score++;
            } else if (strcmp(token, negativeWords[i]) == 0) {
                score--;
            }
        }
        token = strtok(NULL, " ");
    }

    return score;
}