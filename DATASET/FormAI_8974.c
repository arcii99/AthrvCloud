//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

/* Function to determine sentiment score */
int sentiment_score(char *input_text) {
    /* Assigning each word a score */
    int score = 0;
    char *word;
    word = strtok(input_text, " ");
    while (word != NULL) {
        if (strcmp(word, "good") == 0) {
            score += 3;
        }
        else if (strcmp(word, "bad") == 0) {
            score -= 3;
        }
        else if (strcmp(word, "happy") == 0) {
            score += 2;
        }
        else if (strcmp(word, "sad") == 0) {
            score -= 2;
        }
        else if (strcmp(word, "love") == 0) {
            score += 5;
        }
        else if (strcmp(word, "hate") == 0) {
            score -= 5;
        }
        else if (strcmp(word, "excellent") == 0) {
            score += 4;
        }
        else if (strcmp(word, "terrible") == 0) {
            score -= 4;
        }
        else if (strcmp(word, "awesome") == 0) {
            score += 3;
        }
        else if (strcmp(word, "awful") == 0) {
            score -= 3;
        }
        word = strtok(NULL, " ");
    }
    return score;
}

/* Driver code */
int main() {
    char input_text[100];
    printf("Enter your text:\n"); 
    fgets(input_text, 100, stdin);
    int score = sentiment_score(input_text);
    if (score > 0) {
        printf("Positive sentiment with a score of %d\n", score);
    }
    else if (score < 0) {
        printf("Negative sentiment with a score of %d\n", score);
    }
    else {
        printf("Neutral sentiment\n");
    }
    return 0;
}