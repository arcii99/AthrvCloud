//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int positive_words = 0, negative_words = 0;
    float sentiment_score;

    printf("Enter a sentence or phrase: ");
    gets(sentence);

    char* positive_list[] = {"good", "great", "happy", "joyful", "excited", "amazing", "wonderful"};
    char* negative_list[] = {"bad", "awful", "horrible", "unhappy", "sad", "disappointed", "mad"};

    char* word = strtok(sentence, " ");
    while(word != NULL) {
        for(int i=0; i<7; i++) {
            if(strcmp(word, positive_list[i]) == 0) {
                positive_words++;
            }
            if(strcmp(word, negative_list[i]) == 0) {
                negative_words++;
            }
        }
        word = strtok(NULL, " ");
    }

    sentiment_score = (float)(positive_words - negative_words) / (float)(positive_words + negative_words);

    if(sentiment_score > 0.5) {
        printf("\nSentiment analysis result: POSITIVE");
    } else if(sentiment_score > -0.5) {
        printf("\nSentiment analysis result: NEUTRAL");
    } else {
        printf("\nSentiment analysis result: NEGATIVE");
    }

    printf("\nSentiment Score: %f", sentiment_score);

    return 0;
}