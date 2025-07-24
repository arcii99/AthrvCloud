//FormAI DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct MessageType {
    char* message;
    bool is_spam;
} MessageType;

void check_spam(MessageType* message) {
    // Check for known spam words in message
    char* spam_words[] = {"buy", "free", "win", "sex", "credit", "loan", "online", "money", "offer", "discount"};
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

    char* token;
    token = strtok(message->message, " ,.-");
    while (token != NULL) {
        for (int i = 0; i < num_spam_words; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                message->is_spam = true;
                return;
            }
        }
        token = strtok(NULL, " ,.-");
    }

    // Check message length
    if (strlen(message->message) > 50) {
        message->is_spam = true;
        return;
    }

    // If none of the above conditions met, message is not spam
    message->is_spam = false;
}

void process_message(MessageType message) {
    printf("Checking message: %s\n", message.message);
    check_spam(&message);
    if (message.is_spam) {
        printf("Alert! Spam message detected!\n");
    } else {
        printf("Message is not spam.\n");
    }
}

void async_callback(MessageType* message) {
    printf("Message received at %ld\n", time(NULL));
    process_message(*message);
}

int main() {
    // Simulating receiving messages asynchronously at random times
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        MessageType message;

        // Generate random message
        char* messages[] = {"Hello, how are you?", "Buy now, pay later!", "Congratulations, you won!", "Get rich quick!", "Low interest loan available", "Online shopping", "Money back guarantee", "Limited time offer", "50% discount", "Apply now!"};
        int num_messages = sizeof(messages) / sizeof(messages[0]);
        int random_index = rand() % num_messages;
        message.message = messages[random_index];

        // Process message asynchronously
        printf("Receiving message at %ld\n", time(NULL));
        async_callback(&message);

        // Wait random amount of time before receiving next message
        int random_sleep_time = rand() % 5 + 1; // Sleep between 1-5 seconds
        printf("Sleeping for %d seconds...\n", random_sleep_time);
        sleep(random_sleep_time);
    }

    return 0;
}