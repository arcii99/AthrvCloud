//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a sentence or phrase: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    
    int pos_count = 0;
    int neg_count = 0;
    int neut_count = 0;
    
    char *pos_words[] = {"happy", "good", "great", "love", "amazing", "awesome", "excellent", "fantastic"};
    char *neg_words[] = {"sad", "bad", "terrible", "hate", "awful", "crap", "disgusting", "worst"};
    
    char *token;
    token = strtok(input, " ");
    
    while (token != NULL) {
        for (int i=0; i<sizeof(pos_words)/sizeof(char*); i++) {
            if (strcmp(token, pos_words[i]) == 0) {
                pos_count++;
            }
        }
        for (int i=0; i<sizeof(neg_words)/sizeof(char*); i++) {
            if (strcmp(token, neg_words[i]) == 0) {
                neg_count++;
            }
        }
        token = strtok(NULL, " ");
    }
    
    neut_count = len - pos_count - neg_count;
    
    printf("\nSentiment Analysis Result: \n");
    printf("Positive words count: %d\n", pos_count);
    printf("Negative words count: %d\n", neg_count);
    printf("Neutral words count: %d\n", neut_count);
    
    if (pos_count > neg_count) {
        printf("Overall Sentiment: Positive\n");
    }
    else if (neg_count > pos_count) {
        printf("Overall Sentiment: Negative\n");
    }
    else {
        printf("Overall Sentiment: Neutral\n");
    }
    
    return 0;
}