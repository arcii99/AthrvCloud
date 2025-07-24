//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char *positive_words[] = {"good", "great", "awesome", "fantastic"};
    char *negative_words[] = {"bad", "terrible", "awful", "disappointing"};
    int positive_count = 0;
    int negative_count = 0;
    int i;

    printf("Enter your sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character

    // Check for positive words
    for (i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
        if (strstr(input, positive_words[i]) != NULL) {
            positive_count++;
        }
    }

    // Check for negative words
    for (i = 0; i < sizeof(negative_words) / sizeof(negative_words[0]); i++) {
        if (strstr(input, negative_words[i]) != NULL) {
            negative_count++;
        }
    }

    // Determine the sentiment
    if (positive_count > negative_count) {
        printf("Your sentence is positive! Keep spreading the good vibes!\n");
    } else if (positive_count < negative_count) {
        printf("Your sentence is negative. Don't worry though, there's always a chance to turn things around!\n");
    } else {
        printf("Your sentence is neutral. Keep on keeping on!\n");
    }

    return 0;
}