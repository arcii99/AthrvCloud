//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include<stdio.h>
#include<string.h>
#define MAX_SPAM_WORDS 20
#define MAX_SPAM_MESSAGES 50
#define MAX_WORDS_LENGTH 100

int is_spam(char message[MAX_WORDS_LENGTH], char spam_words[MAX_SPAM_WORDS][MAX_WORDS_LENGTH], int num_spam_words) {
    char word[MAX_WORDS_LENGTH];
    char *token;
    
    token = strtok(message, " ");
    while (token != NULL) {
        strcpy(word, token);
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(word, spam_words[i]) == 0) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    int num_spam_words = 3;
    char spam_words[MAX_SPAM_WORDS][MAX_WORDS_LENGTH] = {"buy", "discount", "free"};
    char spam_messages[MAX_SPAM_MESSAGES][MAX_WORDS_LENGTH] = {"Get a free gift with every purchase now!", 
                                                               "Buy now and get a 10% discount!",
                                                               "Congratulations! You have been selected for a free trial!",
                                                               "Hey, buy this amazing product now!",
                                                               "Discounts available for the next 24 hours!"};
    int num_spam_messages = 5;

    for (int i = 0; i < num_spam_messages; i++) {
        int res = is_spam(spam_messages[i], spam_words, num_spam_words);
        if (res == 1) {
            printf("Message %d is spam.\n", i+1);
        } else {
            printf("Message %d is not spam.\n", i+1);
        }
    }
    return 0;
}