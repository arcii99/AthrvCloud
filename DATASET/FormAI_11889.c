//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // maximum allowed length for messages
#define THRESHOLD 0.5 // threshold for spam detection

// function to check if message is spam or not
int is_spam(char message[]) {
    // list of spam words
    char spam_words[][20] = {"free", "win", "discount", "sale", "money", "cash", "urgent", "call now", "limited time offer"};

    // count number of times spam words appear in the message
    int num_spam = 0;
    for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
        char *match = strstr(message, spam_words[i]);
        if (match != NULL) {
            num_spam++;
        }
    }

    // calculate spam score
    float spam_score = (float) num_spam / (float) strlen(message);

    // check if spam score exceeds threshold
    if (spam_score > THRESHOLD) {
        return 1; // message is spam
    }
    else {
        return 0; // message is not spam
    }
}

int main() {
    char message[MAX_LENGTH];

    printf("Enter message: ");
    fgets(message, MAX_LENGTH, stdin);

    if (is_spam(message)) {
        printf("WARNING: This message is spam!\n");
    }
    else {
        printf("This message is not spam.\n");
    }

    return 0;
}