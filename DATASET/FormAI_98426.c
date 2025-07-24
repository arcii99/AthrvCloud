//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

int main() {

    char spam_words[MAX_SPAM_WORDS][20] = {"money", "lottery", "prize", "free", "win", "discount", "credit", "limited", "offer", "urgent"};

    char message[1000];
    int spam_count = 0;

    printf("Enter your message:\n");
    fgets(message, 1000, stdin);

    // Convert message to lowercase
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - 'A' + 'a';
        }
    }

    // Check for spam words
    char *token = strtok(message, " ");
    while (token != NULL) {
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (strcmp(token, spam_words[i]) == 0) {
                spam_count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    // Output result
    if (spam_count > 0) {
        printf("\nALERT: This message appears to be spam with %d spam words.\n", spam_count);
    } else {
        printf("\nThis message does not appear to be spam.\n");
    }

    return 0;
}