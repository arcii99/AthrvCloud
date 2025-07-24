//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char *positive_words[] = {"happy", "love", "excited", "awesome", "great", "fantastic", "amazing"};
    char *negative_words[] = {"sad", "hate", "disappointed", "terrible", "awful", "depressed", "angry"};
    int positive_count = 0, negative_count = 0;
    
    printf("Enter the input text for sentiment analysis:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;
    
    char *word = strtok(input, " ");
    while (word != NULL) {
        for (int i = 0; i < 7; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            } else if (strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " ");
    }
    
    if (positive_count > negative_count) {
        printf("The sentiment of the input text is positive.\n");
    } else if (positive_count < negative_count) {
        printf("The sentiment of the input text is negative.\n");
    } else {
        printf("The sentiment of the input text is neutral.\n");
    }
    
    return 0;
}