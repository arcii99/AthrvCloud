//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define MAX_SPAM 10
#define MAX_STRING_LENGTH 100

int main() {
    char spam_list[MAX_SPAM][MAX_STRING_LENGTH] = {"buy now", "free", "limited time offer", "act fast", "call now", "click here", "earn money", "make money", "work from home", "double your paycheck"};
    char message[MAX_STRING_LENGTH];
    int spam_count = 0;

    printf("Enter your message:\n");
    fgets(message, MAX_STRING_LENGTH, stdin);

    for (int i = 0; i < MAX_SPAM; i++) {
        if (strstr(message, spam_list[i]) != NULL) {
            spam_count++;
        }
    }

    if (spam_count > 0) {
        printf("\n\nSPAM DETECTED!\n\n");
    } else {
        printf("\n\nNo spam detected. This message is safe to send.\n\n");
    }

    return 0;
}