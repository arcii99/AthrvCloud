//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sentiment_score {
    int positive;
    int negative;
} Score;

void calculate_score(char* sentence, Score* score) {
    char* positive_words[] = { "good", "great", "excellent", "awesome" };
    char* negative_words[] = { "bad", "terrible", "awful", "horrible" };
    char* token = strtok(sentence, " ");

    while (token != NULL) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score->positive++;
            }
            else if (strcmp(token, negative_words[i]) == 0) {
                score->negative++;
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    Score score;
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    
    calculate_score(sentence, &score);

    if (score.positive > score.negative) {
        printf("The sentence is positive.\n");
    }
    else if (score.negative > score.positive) {
        printf("The sentence is negative.\n");
    }
    else {
        printf("The sentence is neutral.\n");
    }
    
    return 0;
}