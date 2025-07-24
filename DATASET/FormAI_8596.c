//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

// function to determine sentiment score of a sentence
int getSentimentScore(char *sentence) {
    int score = 0;
    
    // splitting sentence into words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // checking if word has positive or negative sentiment
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            score++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
            score--;
        }
        word = strtok(NULL, " ");
    }
    
    return score;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter a sentence: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // removing newline character from input
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    // getting sentiment score and printing result
    int sentimentScore = getSentimentScore(input);
    printf("Sentiment score for \"%s\" is %d\n", input, sentimentScore);
    
    return 0;
}