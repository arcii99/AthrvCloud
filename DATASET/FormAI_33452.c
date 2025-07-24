//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main(void) {
    char message[1000];
    int spam_count = 0;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Check for spam keywords
    if (strstr(message, "free") != NULL) {
        spam_count++;
    }
    if (strstr(message, "buy now") != NULL) {
        spam_count++;
    }
    if (strstr(message, "limited time offer") != NULL) {
        spam_count++;
    }

    // Check for excessive punctuation
    int exclamation_count = 0;
    int question_count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!') {
            exclamation_count++;
        }
        if (message[i] == '?') {
            question_count++;
        }
    }
    if (exclamation_count > 3 || question_count > 2) {
        spam_count++;
    }

    // Check for all caps
    int is_all_caps = 1;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            is_all_caps = 0;
            break;
        }
    }
    if (is_all_caps) {
        spam_count++;
    }

    // Check if message is too short
    if (strlen(message) < 20) {
        spam_count++;
    }

    // Determine if message is spam or not
    if (spam_count >= 2) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}