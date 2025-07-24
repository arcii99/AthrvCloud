//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Greetings noble sir/madam! I am the Sentiment Analysis Tool!\n");
    printf("Please enter a sentence and let me analyze its sentiment:\n");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
    
    int sentiment_score = 0;
    char *word = strtok(input, " ");
    
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "excellent") == 0 || strcmp(word, "great") == 0) {
            sentiment_score += 3;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
            sentiment_score -= 3;
        } else if (strcmp(word, "love") == 0 || strcmp(word, "like") == 0 || strcmp(word, "enjoy") == 0) {
            sentiment_score += 2;
        } else if (strcmp(word, "hate") == 0 || strcmp(word, "dislike") == 0) {
            sentiment_score -= 2;
        } else if (strcmp(word, "not") == 0 || strcmp(word, "no") == 0) {
            sentiment_score -= 1;
        } else if (strcmp(word, "very") == 0 || strcmp(word, "extremely") == 0) {
            sentiment_score += 1;
        }
        word = strtok(NULL, " ");
    }
    
    printf("After careful analysis, I have determined that the sentiment score of your sentence is %d.\n", sentiment_score);
    printf("That means it is ");
    
    if (sentiment_score >= 5) {
        printf("extremely positive! Huzzah!\n");
    } else if (sentiment_score >= 2) {
        printf("positive. Well done!\n");
    } else if (sentiment_score >= -1) {
        printf("neutral. Could be better, could be worse.\n");
    } else if (sentiment_score >= -4) {
        printf("negative. I recommend improving your vocabulary.\n");
    } else {
        printf("extremely negative. Please consult the local alchemist for a remedy.\n");
    }
    
    return 0;
}