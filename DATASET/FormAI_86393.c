//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin); // Get input from user
    
    int wordCount = 1;
    int positiveWords = 0;
    int negativeWords = 0;

    // Split sentence into words and count positive/negative words
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            positiveWords++; // Found a positive word
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
            negativeWords++; // Found a negative word
        }
        word = strtok(NULL, " ");
        wordCount++;
    }
    
    float positivity = ((float) positiveWords / wordCount) * 100; // Calculate positivity percentage
    float negativity = ((float) negativeWords / wordCount) * 100; // Calculate negativity percentage
    
    printf("\nSentiment Analysis:\n");
    printf("Positive words: %d\n", positiveWords);
    printf("Negative words: %d\n", negativeWords);
    printf("Positivity rating: %.2f%%\n", positivity);
    printf("Negativity rating: %.2f%%\n", negativity);

    return 0;
}