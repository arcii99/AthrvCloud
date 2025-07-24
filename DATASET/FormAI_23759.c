//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20   // Maximum length for a single word
#define MAX_WORDS 1000       // Maximum number of words in our message
#define SPAM_THRESHOLD 0.2   // Percentage of words that must be classified as spam to mark the message as spam

int is_spam(char* message) {
    // List of common spam words and phrases
    char* spam_words[] = {"buy", "free", "limited time", "act now", "offer", "exclusive", "money back", "discount", "lowest price", "get rich", "cash", "credit card", "earn", "extra income", "investment", "multi-level marketing", "work from home", "opportunity"};
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);
    
    // Tokenize the message into individual words
    char* words[MAX_WORDS];
    char* token = strtok(message, " ");
    int num_words = 0;
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }
    
    // Check each word for spam classification
    int num_spam = 0;
    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        int is_spam_word = 0;
        for (int j = 0; j < num_spam_words; j++) {
            if (strstr(word, spam_words[j]) != NULL) {
                is_spam_word = 1;
                break;
            }
        }
        if (is_spam_word) {
            num_spam++;
        }
    }
    
    // Determine if the message is spam or not based on the number of spam words detected
    float spam_ratio = num_spam / (float) num_words;
    if (spam_ratio > SPAM_THRESHOLD) {
        return 1;   // Message is classified as spam
    } else {
        return 0;   // Message is not classified as spam
    }
}

int main() {
    // Example messages to classify
    char message1[] = "Buy now and get 50% off your next purchase! Exclusive offer ends soon! Limited time only!";
    char message2[] = "Hey friend, just wanted to say hi and see how you're doing.";
    
    // Classify the messages
    int is_spam1 = is_spam(message1);
    int is_spam2 = is_spam(message2);
    
    // Print the results
    printf("Message 1: %s\n", is_spam1 ? "SPAM" : "NOT SPAM");
    printf("Message 2: %s\n", is_spam2 ? "SPAM" : "NOT SPAM");
    
    return 0;
}