//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int positive_words = 0, negative_words = 0;
    
    printf("Hello! Thank you for using our Sentiment Analysis Tool\n");
    printf("Please enter your sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    
    char *positive[] = {"good", "happy", "awesome", "love", "excited"};
    char *negative[] = {"bad", "sad", "hate", "dislike", "unhappy"};
    
    char *token = strtok(sentence, " ");
    
    while (token != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive[i]) == 0) {
                positive_words++;
            }
            else if (strcmp(token, negative[i]) == 0) {
                negative_words++;
            }
        }
        token = strtok(NULL, " ");
    }
    
    printf("\nThank you for submitting your sentence!\n");
    printf("Analysis:\n");
    
    if (positive_words > negative_words) {
        printf("Your sentence has a positive sentiment.\n");
    }
    else if (positive_words < negative_words) {
        printf("Your sentence has a negative sentiment.\n");
    }
    else {
        printf("Your sentence does not have a strong sentiment either way.\n");
    }
    
    printf("\nThank you for using our Sentiment Analysis Tool! Have a great day!\n");
    return 0;
}