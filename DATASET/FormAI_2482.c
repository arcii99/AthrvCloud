//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positiveCount = 0, negativeCount = 0;
    float score;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    
    char *positiveWords[] = {"good", "nice", "great", "excellent", "wonderful", "happy", "love"};
    char *negativeWords[] = {"bad", "awful", "terrible", "horrible", "miserable", "disgusting", "hate"};
    
    char *word = strtok(sentence, " ,.?!");
    while (word != NULL) {
        for (int i = 0; i < 7; i++) {
            if (strcmp(word, positiveWords[i]) == 0) {
                positiveCount++;
            }
            if (strcmp(word, negativeWords[i]) == 0) {
                negativeCount++;
            }
        }
        word = strtok(NULL, " ,.?!");
    }
    
    score = ((float)positiveCount / (positiveCount + negativeCount)) * 100;
    printf("Positive count: %d\n", positiveCount);
    printf("Negative count: %d\n", negativeCount);
    printf("Sentiment score: %.2f%%\n", score);
    
    if (score < 50) {
        printf("The sentence has a negative sentiment.\n");
    }
    else if (score > 50) {
        printf("The sentence has a positive sentiment.\n");
    }
    else {
        printf("The sentence has a neutral sentiment.\n");
    }
    
    return 0;
}