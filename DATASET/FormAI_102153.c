//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 1024

// Suspicious keywords
char *spam_keywords[] = {"viagra", "cheap", "money", "win", "prize", "lottery", "bank account", "inheritance"};

// Check if a string contains any of the suspicious keywords
int contains_suspicious_keywords(char *str) {
    int i;
    for (i = 0; i < sizeof(spam_keywords)/sizeof(char*); i++) {
        if (strstr(str, spam_keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Struct for email message
typedef struct EmailMessage {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} EmailMessage;

int main() {
    EmailMessage msg;

    printf("Enter email subject: ");
    fgets(msg.subject, sizeof(msg.subject), stdin);
    msg.subject[strcspn(msg.subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(msg.body, sizeof(msg.body), stdin);
    msg.body[strcspn(msg.body, "\n")] = '\0';

    if (contains_suspicious_keywords(msg.subject) || contains_suspicious_keywords(msg.body)) {
        printf("Warning: This email might be spam!\n");
    } else {
        printf("This email appears to be safe.\n");
    }

    return 0;
}