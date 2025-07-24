//FormAI DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1000
#define SPAM_KEYWORDS_COUNT 5

char spam_keywords[SPAM_KEYWORDS_COUNT][20] = {"Buy Now", "Limited Time Offer", "Enlarge", "Viagra", "Nigerian Prince"};

int is_spam(char *);

int main() {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email message:");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strlen(email) - 1] = '\0';    // Removing trailing newline character

    if (is_spam(email)) {
        printf("This email appears to be spam!\n");
    } else {
        printf("This email looks clean!\n");
    }

    return 0;
}

int is_spam(char *email) {
    int i, j, spam_count = 0;
    char *token;

    token = strtok(email, " ");    // Splitting the email using space as separator

    while(token != NULL) {
        for (i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
            if (strstr(token, spam_keywords[i])) {
                spam_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if (spam_count >= 2 || strlen(email) > MAX_EMAIL_LENGTH * 0.75) {
        return 1;
    } else {
        return 0;
    }
}