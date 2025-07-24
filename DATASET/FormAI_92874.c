//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdbool.h>

int main() {
    char message[100];
    printf("Please enter your message:\n");
    scanf("%[^\n]", &message); // Read input until newline character

    int i = 0;
    int spam_count = 0;
    bool in_word = false;
    bool is_spam = false;

    while (message[i] != '\0') {
        if (message[i] == ' ') {
            in_word = false;
        } else if (!in_word) {
            // Check if word matches spam phrase
            if (message[i] == 'c' && message[i+1] == 'l' && message[i+2] == 'i' && message[i+3] == 'c' && message[i+4] == 'k') {
                spam_count++;
                is_spam = true;
            } else {
                is_spam = false;
            }
            in_word = true;
        }

        i++;
    }

    if (spam_count > 0) {
        printf("SPAM DETECTED: %d instances of 'click' in your message!\n", spam_count);
        printf("Please do not include spam phrases in your message.\n");
    } else {
        printf("Your message is clean!\n");
    }

    return 0;
}