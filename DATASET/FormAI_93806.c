//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1000];
    printf("Enter a sentence to analyze: ");
    fgets(sentence, 1000, stdin);
    int length = strlen(sentence);
    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;
    char *words[100];
    int words_count = 0;
    
    // Splitting the sentence into words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[words_count] = word;
        words_count++;
        word = strtok(NULL, " ");
    }
    
    // Definitions of positive and negative words
    char positive_words[10][20] = {"happy", "love", "amazing", "fantastic", "great", "exciting", "excellent", "pleasure", "enjoy", "satisfied"};
    char negative_words[10][20] = {"hate", "cheat", "terrible", "disgusting", "poison", "killing", "dangerous", "depressing", "painful", "upset"};
    
    // Counting the number of positive, negative and neutral words in the sentence
    for (int i = 0; i < words_count; i++) {
        int positive_flag = 0;
        int negative_flag = 0;
        for (int j = 0; j < 10; j++) {
            if (strcmp(words[i], positive_words[j]) == 0) {
                positive_count++;
                positive_flag = 1;
            }
            if (strcmp(words[i], negative_words[j]) == 0) {
                negative_count++;
                negative_flag = 1;
            }
        }

        if (positive_flag == 0 && negative_flag == 0) {
            neutral_count++;
        }
    }
    
    int total = positive_count + negative_count + neutral_count;
    float positive_percent = 100.0 * (float) positive_count / (float) total;
    float negative_percent = 100.0 * (float) negative_count / (float) total;
    float neutral_percent = 100.0 * (float) neutral_count / (float) total;

    printf("Total words: %d\n", total);
    printf("Positive words: %d (%.2f%%)\n", positive_count, positive_percent);
    printf("Negative words: %d (%.2f%%)\n", negative_count, negative_percent);
    printf("Neutral words: %d (%.2f%%)\n", neutral_count, neutral_percent);

    // Sentiment analysis determination based on percentages
    if (positive_percent > negative_percent && positive_percent > neutral_percent) {
        printf("This sentence is positive.\n");
    } else if (negative_percent > positive_percent && negative_percent > neutral_percent) {
        printf("This sentence is negative.\n");
    } else {
        printf("This sentence is neutral.\n");
    }

  return 0;
}