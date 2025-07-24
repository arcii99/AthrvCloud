//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sentiment_analysis(char* sentence) {
    int positive_count = 0;
    int negative_count = 0;
    int neutral_count = 0;
    int len = strlen(sentence);
    
    // Convert all characters to lowercase
    for(int i=0; i<len; i++) {
        sentence[i] = tolower(sentence[i]);
    }
    
    // Split sentence into words
    char delimiter[] = " ";
    char* token = strtok(sentence, delimiter);
    
    // Loop through each word
    while(token != NULL) {
        // Check if word is positive, negative or neutral
        if(strstr("love like happy good great", token) != NULL) {
            positive_count++;
        } else if(strstr("hate dislike sad bad terrible", token) != NULL) {
            negative_count++;
        } else {
            neutral_count++;
        }
        token = strtok(NULL, delimiter);
    }
    
    // Determine overall sentiment
    if(positive_count > negative_count) {
        printf("Overall sentiment: Positive\n");
    } else if(negative_count > positive_count) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }
    
    // Print results for each word category
    printf("Positive count: %d\n", positive_count);
    printf("Negative count: %d\n", negative_count);
    printf("Neutral count: %d\n", neutral_count);
}

int main() {
    char sentence[100];
    printf("Enter a sentence for sentiment analysis: ");
    fgets(sentence, 100, stdin);
    printf("\n");
    printf("Input sentence: %s\n", sentence);
    sentiment_analysis(sentence);
    return 0;
}