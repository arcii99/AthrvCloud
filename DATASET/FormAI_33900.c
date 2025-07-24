//FormAI DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_SPAM_WORDS 10
#define THRESHOLD 3

char messages[MAX_MESSAGES][100];
char spam_words[MAX_SPAM_WORDS][20];
int spam_count = 0;

int is_spam(char message[]);

int main() {
    int message_count = 0;
    char message[100];

    printf("Welcome to our Spam Detection System!\n");
    printf("Please enter up to 100 messages (enter 'exit' to stop):\n");

    while (1) {
        printf("Message %d: ", message_count + 1);
        fgets(message, 100, stdin);
        message[strcspn(message, "\n")] = 0; //remove newline character
        if (strcmp(message, "exit") == 0) break;
        if (is_spam(message)) {
            printf("SPAM detected, message will be discarded.\n");
        } else {
            strcpy(messages[message_count], message);
            message_count++;
        }
    }

    printf("\nYou entered %d non-spam messages.\n", message_count);
    printf("Here are the messages you entered:\n");
    for (int i = 0; i < message_count; i++) {
        printf("%d. %s\n", i + 1, messages[i]);
    }

    return 0;
}

int is_spam(char message[]) {
    int count = 0;
    char *token;

    token = strtok(message, " ");
    while (token != NULL) {
        for (int i = 0; i < spam_count; i++) {
            if (strcmp(token, spam_words[i]) == 0) count++;
        }
        token = strtok(NULL, " ");
    }

    if (count >= THRESHOLD) return 1;
    else return 0;
}