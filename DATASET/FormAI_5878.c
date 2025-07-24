//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Function to check for spam words
int check_spam(char email[]) {
    char *spam_words[] = {"viagra", "lottery", "inheritance", "prince", "nigeria", "urgently", "free", "$$$"};
    int num_spam_words = sizeof(spam_words) / sizeof(spam_words[0]);

    for (int i = 0; i < num_spam_words; i++) {
        if (strstr(email, spam_words[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char email[100];
    printf("Enter email message: ");
    fgets(email, sizeof(email), stdin);
    // Remove newline character from input string
    email[strcspn(email, "\n")] = '\0';

    if (check_spam(email)) {
        printf("This is a spam message.\n");
    } else {
        printf("This is not a spam message.\n");
    }

    return 0;
}