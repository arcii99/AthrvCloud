//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int positive_count = 0, negative_count = 0;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    sentence[strcspn(sentence, "\n")] = 0; // remove newline character
    
    // convert all characters to lowercase for matching
    for (int i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }
    
    // compile list of positive and negative words
    char *positive_words[10] = {"happy", "love", "great", "amazing", "pleasure", "excited", "joy", "fun", "laugh", "like"};
    char *negative_words[10] = {"sad", "hate", "bad", "horrible", "pain", "disappointed", "regret", "stress", "anger", "dislike"};
    
    // loop through sentence and count positive and negative words
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            }
            if (strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " ");
    }
    
    // determine overall sentiment based on word count
    if (positive_count > negative_count) {
        printf("Sentiment: Positive");
    }
    else if (negative_count > positive_count) {
        printf("Sentiment: Negative");
    }
    else {
        printf("Sentiment: Neutral");
    }
    
    return 0;
}