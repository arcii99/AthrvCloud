//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_SCORE 10
#define MAX_MESSAGES 1000

typedef struct {
    char message[101];
    int spamScore;
} Message;

int numMessages = 0;
Message messages[MAX_MESSAGES];

void addMessage(char message[]) {
    if(numMessages < MAX_MESSAGES) {
        Message newMessage;
        strcpy(newMessage.message, message);
        newMessage.spamScore = 0;
        messages[numMessages++] = newMessage;
    }
}

int containsKeywords(char message[]) {
    char *keywords[] = {"buy", "sell", "enlarge", "earn", "money", "cash", "win", "free", "limited time", "act fast"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for(int i = 0; i < numKeywords; i++) {
        if(strstr(message, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void updateSpamScores() {
    for(int i = 0; i < numMessages; i++) {
        if(containsKeywords(messages[i].message)) {
            messages[i].spamScore++;
        }
        if(messages[i].spamScore >= MAX_SPAM_SCORE) {
            printf("Detected spam message: %s\n", messages[i].message);
            messages[i].spamScore = 0;
        }
    }
}

int main() {
    addMessage("Buy this limited time offer now!");
    addMessage("Get rich quick and earn money fast!");
    addMessage("Win a free vacation by acting fast!");
    addMessage("Hello there, how are you doing?");
    addMessage("Limited time offer, act now and get cash back!");

    updateSpamScores();

    return 0;
}