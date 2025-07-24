//FormAI DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 4

int countSpam(char *msg) {
    int count = 0;
    char *ptr;
    char *spamWords[] = {"free", "money", "click", "subscribe"};
    for (int i = 0; i < SPAM_THRESHOLD; i++) {
        ptr = strstr(msg, spamWords[i]); // Find potential spam word
        while(ptr != NULL) { // While potential spam word exists
            count++; // Increment count of potential spam messages
            ptr = strstr(ptr + strlen(spamWords[i]), spamWords[i]); // Look for more instances of the same potential spam word
        }
    }
    return count;
}

int main() {
    char message[256];
    printf("Enter your message: ");
    fgets(message, 256, stdin);
    int spamCount = countSpam(message);
    if (spamCount >= SPAM_THRESHOLD) {
        printf("Warning: This message may be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }
    return 0;
}