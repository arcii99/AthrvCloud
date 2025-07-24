//FormAI DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define SPAM_THRESHOLD 0.5

int main(){
    char message[MAX_SIZE];
    int i, j, num_words = 1, num_spam_words = 0;
    double spam_score;

    // Create an array of known spam words
    char *spam_words[] = {"buy", "sale", "free", "limited", "discount", "money-back", "click", "unsubscribe"};

    // Ask user to input message
    printf("Please enter your message:\n");
    fgets(message, MAX_SIZE, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;

    // Convert message to lowercase for case-insensitive checking
    for(i = 0; message[i]; i++){
        message[i] = tolower(message[i]);
    }

    // Calculate the number of words
    for(i = 0; message[i]; i++){
        if(message[i] == ' ')
            num_words++;
    }

    // Check each word in the message for spam words
    char *token = strtok(message, " ");
    while(token != NULL){
        for(i = 0; i < 8; i++){
            if(strcmp(token, spam_words[i]) == 0){
                num_spam_words++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Calculate the spam score
    spam_score = (double)num_spam_words / (double)num_words;

    // Determine if message is spam or ham
    if(spam_score > SPAM_THRESHOLD){
        printf("This message has been identified as spam. Please do not send unsolicited messages.\n");
    }else{
        printf("This message has been identified as a legitimate message. Thank you for your communication.\n");
    }

    return 0;
}