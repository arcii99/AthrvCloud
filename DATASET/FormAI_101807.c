//FormAI DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    int score = 0;
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        // Check for excessive use of capital letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            score += 1;
        }

        // Check for excessive use of exclamation marks
        if (message[i] == '!') {
            score += 2;
        }

        // Check for excessive use of question marks
        if (message[i] == '?') {
            score += 2;
        }

        // Check for use of common spam words
        char* spam_words[] = {"win", "prize", "discount", "viagra", "enlargement", "promise", "free"};
        int num_spam_words = sizeof(spam_words) / sizeof(char*);
        for (int j = 0; j < num_spam_words; j++) {
            if (strstr(message, spam_words[j]) != NULL) {
                score += 3;
            }
        }
    }

    if (score >= 10) {
        printf("Your message has been detected as spam.\n");
    } else {
        printf("Your message is not spam.\n");
    }

    return 0;
}