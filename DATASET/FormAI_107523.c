//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void removeNewLine(char* str) {
    int len = strlen(str);
    if (str[len-1] == '\n')
        str[len-1] = '\0';
}

int analyzeSentiment(char* sentence) {
    char negativeWords[5][10] = {"hate", "anger", "disgust", "sad", "depressed"};
    char positiveWords[5][10] = {"love", "happiness", "joy", "excited", "thrilled"};

    int score = 0;

    char* word = strtok(sentence, " ");

    while (word != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(negativeWords[i], word) == 0) {
                score -= 1;
                break;
            } else if (strcmp(positiveWords[i], word) == 0) {
                score += 1;
                break;
            }
        }

        word = strtok(NULL, " ");
    }

    return score;
}

int main() {
    printf("Welcome to Sentiment Analysis!\n\nEnter a sentence to analyze: ");

    char sentence[100];
    fgets(sentence, 100, stdin);
    removeNewLine(sentence);

    int score = analyzeSentiment(sentence);

    if (score < 0) {
        printf("\nThis sentence has a negative sentiment.\nScore: %d\n", score);
    } else if (score > 0) {
        printf("\nThis sentence has a positive sentiment.\nScore: %d\n", score);
    } else {
        printf("\nThis sentence is neutral.\nScore: %d\n", score);
    }

    return 0;
}