//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int analyze_sentiment(char *sentence);

int main() {
    char user_input[1000];
    printf("Type a sentence to analyze its sentiment:\n");
    fgets(user_input, 1000, stdin);

    int result = analyze_sentiment(user_input);
    if (result == 1) {
        printf("The sentence has a positive sentiment.\n");
    } else if (result == -1) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}

int analyze_sentiment(char *sentence) {
    int positive_words = 0;
    int negative_words = 0;
    int i;

    // List of positive and negative words to match against
    char *positive_list[] = {"good", "great", "happy", "love", "like", "excellent", "awesome", "fantastic", "wonderful", "amazing"};
    char *negative_list[] = {"bad", "terrible", "hate", "dislike", "awful", "horrible", "disgusting", "gross", "unpleasant", "lousy"};

    // Convert sentence to lowercase
    for (i = 0; sentence[i]; i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Check for positive and negative words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        for (i = 0; i < 10; i++) {
            if (strcmp(word, positive_list[i]) == 0) {
                positive_words++;
            }
            if (strcmp(word, negative_list[i]) == 0) {
                negative_words++;
            }
        }
        word = strtok(NULL, " ");
    }

    // Determine sentiment based on word count
    if (positive_words > negative_words) {
        return 1;
    } else if (negative_words > positive_words) {
        return -1;
    } else {
        return 0;
    }
}