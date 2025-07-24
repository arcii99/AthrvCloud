//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>

int checkSpam(char *msg) {
    // Check for common spam keywords
    char *keywords[] = {"buy", "free", "money", "click", "discount"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strstr(msg, keywords[i])) {
            return 1;
        }
    }

    // Check for excessive exclamation marks and capital letters
    int numExclamations = 0;
    int numCapitals = 0;
    int msgLen = strlen(msg);
    for (int i = 0; i < msgLen; i++) {
        if (msg[i] == '!') {
            numExclamations++;
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            numCapitals++;
        }
    }
    if (numExclamations >= 3 || numCapitals >= msgLen / 2) {
        return 1;
    }

    // Check for suspicious links
    char *linkStr = "http";
    char *link = strstr(msg, linkStr);
    if (link && (link == msg || *(link - 1) == ' ') && *(link + strlen(linkStr)) != ' ') {
        return 1;
    }

    // Passed all checks, not spam
    return 0;
}

int main() {
    char *msg1 = "Get rich quick! Click here for a discount on money!";
    char *msg2 = "Great deal! Purchase now and receive a free gift!";
    char *msg3 = "Hey, I wanted to send you this link: http://www.example.com/secret-page";
    char *msg4 = "Hello there, how are you doing?";
    
    if (checkSpam(msg1)) {
        printf("Message 1 is spam.\n");
    }
    if (checkSpam(msg2)) {
        printf("Message 2 is spam.\n");
    }
    if (checkSpam(msg3)) {
        printf("Message 3 is spam.\n");
    }
    if (checkSpam(msg4)) {
        printf("Message 4 is spam.\n");
    }

    return 0;
}