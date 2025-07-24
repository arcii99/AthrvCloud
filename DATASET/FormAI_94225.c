//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int i, j;
    int score = 0;

    printf("Enter text for sentiment analysis: ");
    fgets(text, 1000, stdin);
    
    // Removing new line character from input
    text[strcspn(text, "\n")] = 0;
    
    // Converting input to lowercase
    for(i = 0; text[i]; i++){
        text[i] = tolower(text[i]);
    }
    
    // Counting score based on positive and negative words
    char* positive_words[] = {"amazing", "awesome", "fantastic", "great", "love", "nice", "super", "wonderful"};
    char* negative_words[] = {"bad", "horrible", "lousy", "poor", "terrible", "worst"};
    
    for(i = 0; text[i]; i++){
        for(j = 0; j < 8; j++){
            if(strstr(&text[i], positive_words[j]) == &text[i]){
                score++;
                i += strlen(positive_words[j]) - 1;
                break;
            }
        }
        
        for(j = 0; j < 6; j++){
            if(strstr(&text[i], negative_words[j]) == &text[i]){
                score--;
                i += strlen(negative_words[j]) - 1;
                break;
            }
        }
    }
    
    // Determining sentiment and printing final score
    if(score > 0){
        printf("\nPositive sentiment detected! Score: %d\n", score);
    }
    else if(score < 0){
        printf("\nNegative sentiment detected! Score: %d\n", score);
    }
    else {
        printf("\nNeutral sentiment detected! Score: %d\n", score);
    }

    return 0;
}