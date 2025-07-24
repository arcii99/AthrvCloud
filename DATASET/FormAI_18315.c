//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define SPAM_THRESHOLD 0.5

int main() {
    char message[MAX_SIZE];
    int spam_words = 0;
    int total_words = 0;
    float spam_score;

    printf("Enter your message: ");
    fgets(message, MAX_SIZE, stdin);

    // Count the number of spam words in the message
    char *token = strtok(message, " ");
    while (token != NULL) {
        total_words++;
        if (strcmp(token, "buy") == 0 || strcmp(token, "sale") == 0 ||
            strcmp(token, "discount") == 0 || strcmp(token, "offer") == 0) {
            spam_words++;
        }
        token = strtok(NULL, " ");
    }

    // Calculate the spam score and determine if it is spam
    spam_score = (float)spam_words / total_words;
    if (spam_score >= SPAM_THRESHOLD) {
        printf("This message has been flagged as spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}