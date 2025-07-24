//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include<stdio.h>
#include<string.h>

// Function to classify sentiment
void classify_sentiment(char *text) {
    
    // List of positive words
    char *pos_words[] = {"happy", "love", "great", "excited", "fun", "amazing", "awesome", "fantastic", "wonderful", "good", "excellent"};
    
    // List of negative words
    char *neg_words[] = {"sad", "hate", "bad", "angry", "disappointed", "terrible", "horrible", "awful", "poor", "unhappy", "unpleasant"};
    
    int pos_count = 0; //keep count of positive words
    int neg_count = 0; //keep count of negative words
    
    char *word = strtok(text, " "); //split string into words
    
    while (word != NULL) {
        for (int i = 0; i < 11; i++) {
            if (strcmp(word, pos_words[i]) == 0) {
                pos_count++;
            } else if (strcmp(word, neg_words[i]) == 0) {
                neg_count++;
            }
        }
        
        word = strtok(NULL, " "); //get next word
    }
    
    // Determine sentiment based on word count
    if (pos_count > neg_count) {
        printf("Sentiment is positive.\n");
    } else if (pos_count < neg_count) {
        printf("Sentiment is negative.\n");
    } else {
        printf("Sentiment is neutral.\n");
    }
}

int main() {
    char text[256];

    printf("Enter text for sentiment analysis: ");
    fgets(text, 256, stdin);
    
    classify_sentiment(text);
    
    return 0;
}