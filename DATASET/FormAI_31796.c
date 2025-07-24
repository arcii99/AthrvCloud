//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <string.h>

// Define the maximum length of the message and the threshold for spam detection
#define MAX_LENGTH 1000
#define THRESHOLD 0.7

// Define the function to check if the message contains spam keywords
int check_spam(char *message) {
    char *spam_keywords[] = {"buy", "sell", "discount", "promo", "click", "money", "cash", "free", "offer", "limited"};
    int num_spam_keywords = sizeof(spam_keywords) / sizeof(spam_keywords[0]);

    int num_spam = 0;
    for (int i = 0; i < num_spam_keywords; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            num_spam++;
        }
    }

    return num_spam;
}

int main() {
    // Get the input message from the user
    char message[MAX_LENGTH] = {0};
    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);

    // Check if the message contains spam keywords
    int num_spam = check_spam(message);

    // Calculate the ratio of spam keywords in the message
    float ratio_spam = (float)num_spam / (float)strlen(message);

    // Check if the message is spam or not
    if (ratio_spam > THRESHOLD) {
        printf("Your message contains spam!\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}