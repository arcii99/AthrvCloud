//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LEN 1000
#define THRESHOLD_SCORE 0.7

double compute_spam_score(char *message);
void print_result(double score);

int main() {
    char message[MAX_MESSAGE_LEN];
    double score;

    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LEN, stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    score = compute_spam_score(message);
    print_result(score);

    return 0;
}

double compute_spam_score(char *message) {
    int i, length = strlen(message);
    double score = 0.0;

    for (i = 0; i < length; i++) {
        if (message[i] == 'b') {
            score += 0.5;
        } else if (message[i] == 'c') {
            score += 0.6;
        } else if (message[i] == 'v') {
            score += 0.4;
        }
    }

    return score / length; // Normalize score by dividing by message length
}

void print_result(double score) {
    if (score >= THRESHOLD_SCORE) {
        printf("This message is classified as spam with a score of %f\n", score);
    } else {
        printf("This message is classified as not spam with a score of %f\n", score);
    }
}