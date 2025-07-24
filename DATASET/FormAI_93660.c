//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_KEYWORDS 4 // Number of spam keywords to check
#define MAX_SPAM_COUNT 10 // Maximum number of spam occurrences before flagging
#define MAX_MESSAGE_LEN 100 // Maximum length of message

char *spam_keywords[SPAM_KEYWORDS] = {"money", "gift", "free", "lottery"}; // List of spam keywords

int detect_spam(char *message) {
    int i, count = 0;
    char *token;
    char temp[MAX_MESSAGE_LEN];
    strcpy(temp, message);
    
    token = strtok(temp, " ");
    while (token != NULL) {
        for (i=0; i<SPAM_KEYWORDS; i++) {
            if (strcmp(token, spam_keywords[i]) == 0) {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }
    
    return count;
}

int main() {
    char message[MAX_MESSAGE_LEN];
    int spam_count = 0;
    
    printf("Enter your message:\n");
    fgets(message, MAX_MESSAGE_LEN, stdin); // Read message from user
    
    spam_count = detect_spam(message);
    
    if (spam_count > MAX_SPAM_COUNT) {
        printf("Possible spam detected!\n");
    } else {
        printf("Message is not spam.\n");
    }
    
    return 0;
}