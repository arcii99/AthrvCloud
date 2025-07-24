//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
/* Linus Torvalds style C Sentiment analysis tool example program */
#include <stdio.h>

/* Define arrays for positive and negative words */
char *pos_words[] = {"love", "happy", "amazing", "great", "awesome"};
char *neg_words[] = {"hate", "sad", "terrible", "awful", "disappointing"};

/* Define counters for positive and negative words */
int pos_counter = 0;
int neg_counter = 0;

int main() {
    char input[256];
    printf("Enter a sentence to analyze: ");
    fgets(input, 256, stdin);
    
    /* Loop through input string and compare words to positive and negative arrays */
    char *token = strtok(input, " ");
    while(token != NULL) {
        for(int i = 0; i < 5; i++) {
            if(strcmp(token, pos_words[i]) == 0) {
                pos_counter++;
            }
            else if(strcmp(token, neg_words[i]) == 0) {
                neg_counter++;
            }
        }
        token = strtok(NULL, " ");
    }
    
    /* Determine overall sentiment based on word counts */
    if(pos_counter > neg_counter) {
        printf("Sentiment: Positive\n");
    }
    else if(pos_counter < neg_counter) {
        printf("Sentiment: Negative\n");
    }
    else {
        printf("Sentiment: Neutral\n");
    }
    
    return 0;
}