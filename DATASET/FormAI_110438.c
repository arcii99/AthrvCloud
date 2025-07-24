//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define MAX_SPAM_WORDS 10
#define MAX_MESSAGE_LENGTH 100

// Function to check if the given word is a spam word or not
bool isSpamWord(char* word) {
    char spamWords[MAX_SPAM_WORDS][10] = {"buy", "discount", "sale", "limited", "act now", "subscribe", "win", "money", "cash", "credit"};
    
    for(int i=0; i<MAX_SPAM_WORDS; i++) {
        if(strcmp(word, spamWords[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Convert message to lowercase
    for(int i=0; message[i]; i++){
        message[i] = tolower(message[i]);
    }

    char word[MAX_MESSAGE_LENGTH];
    int count = 0;

    // Loop through the message and count number of spam words
    for(int i=0, j=0; message[i]; i++) {
        if(message[i] == ' ' || message[i] == '\n') {
            word[j] = '\0';
            j = 0;
            if(isSpamWord(word)) {
                count++;
            }
        }
        else {
            word[j] = message[i];
            j++;
        }
    }

    // Check if message is spam or not
    if(count > 2) {
        printf("This message is spam\n");
    }
    else {
        printf("This message is not spam\n");
    }

    return 0;
}