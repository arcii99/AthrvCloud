//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100
#define SPAM_KEYWORDS {"buy", "sale", "discount", "money", "win", "free"}

int spam_detector(char* message) {
    char* keywords[] = SPAM_KEYWORDS;
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(message, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter a message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    if (spam_detector(message)) {
        printf("This message is spam.\n");
    }
    else {
        printf("This message is not spam.\n");
    }
    return 0;
}