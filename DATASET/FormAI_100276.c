//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main(){
    
    char input[100];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(input, 100, stdin); //take input from user
    input[strcspn(input, "\n")] = '\0'; //remove newline character
    
    char positiveKeywords[8][20] = {"love", "amazing", "great", "happy", "like", "awesome", "perfect", "superb"};
    char negativeKeywords[8][20] = {"hate", "terrible", "awful", "sad", "dislike", "ugly", "horrible", "worst"};
    
    int sentiment = 0;
    
    char *word = strtok(input, " "); //split input into words
    
    while (word != NULL) {
        
        for (int i = 0; i < 8; i++) {
            if (strcmp(word, positiveKeywords[i]) == 0) {
                sentiment++; //add 1 for each positive keyword found
            }
            if (strcmp(word, negativeKeywords[i]) == 0) {
                sentiment--; //subtract 1 for each negative keyword found
            }
        }
        
        word = strtok(NULL, " "); //get next word
    }
    
    if (sentiment > 0) {
        printf("The sentiment is Positive\n");
    }
    else if (sentiment < 0) {
        printf("The sentiment is Negative\n");
    }
    else {
        printf("The sentiment is Neutral\n");
    }
    
    return 0;
}