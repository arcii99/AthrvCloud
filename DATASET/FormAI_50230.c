//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char sentence[1000];
    int pos_count = 0, neg_count = 0, neu_count = 0, total_count = 0;

    printf("Enter a sentence to analyze: ");
    fgets(sentence, 1000, stdin);

    // Splitting the sentence into words
    char *word = strtok(sentence, " ");

    // Looping through each word
    while (word != NULL) {
        // Checking whether the word is positive, negative, or neutral
        if(strcmp(word, "happy") == 0 || strcmp(word, "good") == 0 || strcmp(word, "love") == 0 || strcmp(word, "like") == 0){
            pos_count++;
        }
        else if(strcmp(word, "sad") == 0 || strcmp(word, "bad") == 0 || strcmp(word, "hate") == 0 || strcmp(word, "dislike") == 0){
            neg_count++;
        }
        else{
            neu_count++;
        }
        // Moving to the next word
        word = strtok(NULL, " ");
        total_count++;
    }

    // Printing the result
    printf("Total words: %d\n", total_count);
    printf("Positive words: %d\n", pos_count);
    printf("Negative words: %d\n", neg_count);
    printf("Neutral words: %d\n", neu_count);

    if(pos_count > neg_count){
        printf("The sentence is positive.\n");
    }
    else if(neg_count > pos_count){
        printf("The sentence is negative.\n");
    }
    else{
        printf("The sentence is neutral.\n");
    }

    return 0;
}