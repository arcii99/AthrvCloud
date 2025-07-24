//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5

// Function to calculate spam score of a message
float calculate_spam_score(char* message, int len) {
    int i, count = 0;
    float score;

    for (i = 0; i < len; i++) {
        if (message[i] == 's' || message[i] == 'S') {
            count++;
        }
    }

    score = (float)count / (float)len;

    return score;
}

// Function to determine if a message is spam or not
int is_spam(char* message, int len) {
    float score = calculate_spam_score(message, len);

    if (score >= SPAM_THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[100];
    int len;

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    len = strlen(message);

    if (is_spam(message, len) == 1) {
        printf("SPAM detected!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}