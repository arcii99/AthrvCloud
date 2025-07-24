//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int positive_count;
    int negative_count;
    float overall_score;
} SentimentAnalysis;

float calculateOverallScore(SentimentAnalysis *analysis) {
    float overall_score = (float) (analysis->positive_count - analysis->negative_count) / (analysis->positive_count + analysis->negative_count);
    analysis->overall_score = overall_score;
    return overall_score;
}

void analyzeSentiment(char* sentence, SentimentAnalysis* analysis) {
    char* positive_words[5] = {"good", "awesome", "great", "excellent", "fantastic"};
    char* negative_words[5] = {"bad", "terrible", "awful", "poor", "disappointing"};

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                analysis->positive_count += 1;
                break;
            } else if (strcmp(word, negative_words[i]) == 0) {
                analysis->negative_count += 1;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    calculateOverallScore(analysis);
}

int main() {
    char sentence[] = "The restaurant had excellent service, but the food was disappointing.";
    SentimentAnalysis analysis = {0, 0, 0};

    analyzeSentiment(sentence, &analysis);

    printf("Positive words count: %d\n", analysis.positive_count);
    printf("Negative words count: %d\n", analysis.negative_count);
    printf("Overall score: %f\n", analysis.overall_score);

    return 0;
}