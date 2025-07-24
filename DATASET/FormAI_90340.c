//FormAI DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000
#define SPAM_KEYWORDS {"viagra", "lottery", "prize", "free", "cash", "enlarge", "earn", "income"}

int main() {
    char msg[MAX_MSG_LENGTH];
    char* spam_keywords[] = SPAM_KEYWORDS;
    int count = sizeof(spam_keywords) / sizeof(char*);
    int i, j, spam_count = 0;

    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);

    for (i = 0; i < count; i++) {
        char* keyword = spam_keywords[i];
        int keyword_len = strlen(keyword);

        for (j = 0; j < strlen(msg); j++) {
            if (msg[j] == keyword[0]) {
                if (strncmp(&msg[j], keyword, keyword_len) == 0) {
                    spam_count++;
                }
            }
        }
    }

    if (spam_count > 0) {
        printf("\nError: Message marked as spam\n");
    } else {
        printf("\nMessage sent successfully\n");
    }

    return 0;
}