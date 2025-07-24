//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MSG_LEN 100  // maximum length of a message
#define SPAM_THRESH 3     // number of occurrences needed for a message to be marked as spam
#define STORED_MSGS 10    // maximum number of messages stored in the history array

// struct to represent a single message
typedef struct {
    char content[MAX_MSG_LEN];
    bool is_spam;
} Message;

// function to check if a given message has already been stored in the history array
bool is_duplicate(Message history[], char content[]) {
    for (int i = 0; i < STORED_MSGS; i++) {
        if (strcmp(history[i].content, content) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("Welcome to the Spam Detection System!\n");

    Message history[STORED_MSGS];  // array to store previously received messages
    int num_received = 0;          // number of messages received so far

    while (true) {
        char new_msg[MAX_MSG_LEN];
        printf("Enter a new message:\n");
        fgets(new_msg, MAX_MSG_LEN, stdin);

        // remove the newline character from the end of the input string
        new_msg[strcspn(new_msg, "\n")] = 0;

        if (is_duplicate(history, new_msg)) {
            printf("This message has already been received!\n");
            continue;
        }

        // add the new message to the history array
        Message msg = { .is_spam = false };
        strcpy(msg.content, new_msg);
        history[num_received % STORED_MSGS] = msg;
        num_received++;

        // check if the new message appears frequently enough to be considered spam
        int count = 0;
        for (int i = 0; i < STORED_MSGS; i++) {
            if (strcmp(history[i].content, new_msg) == 0) {
                count++;
                if (count >= SPAM_THRESH) {
                    printf("WARNING: This message may be spam!\n");
                    msg.is_spam = true;
                    history[num_received % STORED_MSGS] = msg;
                    break;
                }
            }
        }

        printf("Message received: %s\n", new_msg);
        if (msg.is_spam) {
            printf("This message has been marked as spam.\n");
        }
    }

    return 0;
}