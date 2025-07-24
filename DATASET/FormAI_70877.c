//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
/* 
 * This program is a sentimental analysis tool that analyzes the sentiment of a given text by 
 * counting the number of positive, negative and neutral words in the text. 
 */

#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int pos_count = 0;  // count of positive words
    int neg_count = 0;  // count of negative words
    int neu_count = 0;  // count of neutral words
    
    // positive words array
    char *pos_words[] = {"love", "happy", "excited", "success", "amazing", "great", "wonderful", "fantastic", "excellent", "fabulous"};
    int pos_size = sizeof(pos_words) / sizeof(pos_words[0]);
    
    // negative words array
    char *neg_words[] = {"hate", "sad", "angry", "failure", "bad", "terrible", "awful", "horrible", "disappointing", "unsatisfactory"};
    int neg_size = sizeof(neg_words) / sizeof(neg_words[0]);

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
    
    // check each word in the text
    char *word = strtok(text, " .\n");
    while (word != NULL) {
        int found = 0;
        
        // check if the word is positive
        for (int i = 0; i < pos_size; i++) {
            if (strcmp(word, pos_words[i]) == 0) {
                pos_count++;
                found = 1;
                break;
            }
        }
        
        // check if the word is negative
        for (int i = 0; i < neg_size; i++) {
            if (strcmp(word, neg_words[i]) == 0) {
                neg_count++;
                found = 1;
                break;
            }
        }
        
        // if the word is not positive or negative, it's neutral
        if (!found) {
            neu_count++;
        }
        
        word = strtok(NULL, " .\n");
    }
    
    // print the sentiment analysis result
    printf("\nSentiment Analysis: \n");
    printf("Positive Words Count: %d\n", pos_count);
    printf("Negative Words Count: %d\n", neg_count);
    printf("Neutral Words Count: %d\n", neu_count);
    
    return 0;
}