//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SPAM_THRESHOLD 3
#define MAX_MESSAGES 10

typedef struct {
    char message[100];
    bool isSpam;
} Message;

typedef struct {
    Message messages[MAX_MESSAGES];
    int count;
} MessageList;

void markAsSpam(Message* message) {
    printf("Marking message as spam: %s\n", message->message);
    message->isSpam = true;
}

bool isSpam(MessageList* messageList, char* message) {
    int spamCount = 0;

    for(int i = 0; i < messageList->count; i++) {
        if(strcmp(messageList->messages[i].message, message) == 0) {
            printf("Duplicate message found: %s\n", message);
            markAsSpam(&messageList->messages[i]);
        }

        if(messageList->messages[i].isSpam) {
            spamCount++;
        }
    }

    if(spamCount >= SPAM_THRESHOLD) {
        return true;
    }

    return false;
}

void addMessage(MessageList* messageList, char* message) {
    bool spam = isSpam(messageList, message);

    Message newMessage;
    strcpy(newMessage.message, message);
    newMessage.isSpam = spam;

    messageList->messages[messageList->count++] = newMessage;

    printf("New message added: %s\n", message);
    if(spam) {
        printf("Message marked as spam: %s\n", message);
    }
}

int main() {
    MessageList messageList;
    messageList.count = 0;

    addMessage(&messageList, "Buy our new product, now on sale!");
    addMessage(&messageList, "Buy our new product, now on sale!");
    addMessage(&messageList, "Buy our sneaky product, now on sale!");
    addMessage(&messageList, "Solve all your problems with our new product!");
    addMessage(&messageList, "Click here for free money!");
    addMessage(&messageList, "Earn money quickly and easily!");
    addMessage(&messageList, "Looking for a job? Look no further!");
    addMessage(&messageList, "Looking for a job? Look no further!");
    addMessage(&messageList, "Looking for a job? Look no further!");
    addMessage(&messageList, "Get our exclusive offer now, limited time only!");

    return 0;
}