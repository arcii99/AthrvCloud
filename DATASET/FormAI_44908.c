//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int positive_count = 0, negative_count = 0;
    float sentiment_score;

    printf("Enter your sentence:\n");
    fgets(sentence, 1000, stdin);

    // Positive sentiment words
    char positive[8][20] = {"awesome", "fantastic", "great", "love", "amazing", "excellent", "wonderful", "happy"};

    // Negative sentiment words
    char negative[8][20] = {"terrible", "awful", "bad", "hate", "dislike", "horrible", "dreadful", "sad"};

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // Remove any punctuation from the word
        int len = strlen(word);
        int j = 0;
        for (int i = 0; i < len; i++) {
            if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
                word[j++] = word[i];
            }
        }
        word[j] = '\0';

        // Check if the word is present in the positive list or negative list
        for (int i = 0; i < 8; i++) {
            if (strcmp(word, positive[i]) == 0) {
                positive_count++;
            }

            if (strcmp(word, negative[i]) == 0) {
                negative_count++;
            }
        }

        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    sentiment_score = (float) (positive_count - negative_count) / (positive_count + negative_count);

    // Analyze the sentiment score and print the result
    if (sentiment_score > 0) {
        printf("Your sentence has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("Your sentence has a negative sentiment.\n");
    } else {
        printf("Your sentence has a neutral sentiment.\n");
    }

    return 0;
}