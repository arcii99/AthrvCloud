//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void analyze_sentiment(char *text);

int main() {
    char input_text[MAX_LENGTH];
    printf("Enter some text to analyze: ");
    fgets(input_text, MAX_LENGTH, stdin);
    analyze_sentiment(input_text);
    return 0;
}

void analyze_sentiment(char *text) {
    int length = strlen(text);
    if (length == 0) {
        printf("Error: Empty input.\n");
        return;
    }
    // calculate the sentiment score by counting positive and negative words
    int positive_score = 0;
    int negative_score = 0;
    char word[MAX_LENGTH];
    char *delimiters = " \n\t,.!?:;";
    char *token = strtok(text, delimiters);
    while (token != NULL) {
        strcpy(word, token);
        // convert word to lowercase for case-insensitive matching
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] += ('a' - 'A');
            }
        }
        // check if word is positive or negative and update score
        if (strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "great") == 0) {
            positive_score++;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
            negative_score++;
        }
        token = strtok(NULL, delimiters);
    }
    // calculate sentiment score as a percentage of total words
    float total_score = (float)(positive_score - negative_score) / length * 100;
    printf("Sentiment score: %.2f%%\n", total_score);
}