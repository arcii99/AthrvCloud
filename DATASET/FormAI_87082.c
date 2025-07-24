//FormAI DATASET v1.0 Category: Spam Detection System ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100 // Maximum message length allowed
#define MAX_SPAM_ATTEMPTS 3 // Maximum number of spam attempts allowed
#define THRESHOLD 0.6 // Threshold value for spam detection

int main() {
    char msg[MAX_MSG_LENGTH+1]; // Message buffer
    int num_spam_attempts = 0; // Number of spam attempts so far
    float spam_prob = 0.0; // Probability of message being spam
    int i;

    while(num_spam_attempts < MAX_SPAM_ATTEMPTS) { // Keep tracking spam attempts until threshold is reached
        printf("Enter your message: ");
        fgets(msg, MAX_MSG_LENGTH, stdin); // Read user input
        msg[strcspn(msg, "\n")] = 0; // Remove newline character

        // Calculate spam probability for current message
        spam_prob = 0.0;
        for(i = 0; i < strlen(msg); i++) {
            if(msg[i] >= 'a' && msg[i] <= 'z')
                spam_prob += 0.01;
            else if(msg[i] >= 'A' && msg[i] <= 'Z')
                spam_prob += 0.02;
            else if(msg[i] >= '0' && msg[i] <= '9')
                spam_prob += 0.05;
            else // Special character
                spam_prob += 0.1;
        }

        if(spam_prob >= THRESHOLD) { // Message is classified as spam
            num_spam_attempts++;
            printf("Warning: Potential spam detected! Number of attempts: %d\n", num_spam_attempts);
        }
        else { // Message is not spam
            printf("Message received. Thank you!\n");
        }
    }

    printf("Warning: Maximum number of attempts reached. Please try again later.\n");

    return 0;
}