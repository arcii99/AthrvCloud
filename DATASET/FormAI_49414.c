//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_LENGTH 100
#define MAX_MSG_LENGTH 1000

int check_spam(char msg[], char spam[][MAX_SPAM_LENGTH], int num_spam) {
    int count = 0;
    char *token = strtok(msg, " ");
    while (token != NULL) {
        for (int i = 0; i < num_spam; i++) {
            if (strcmp(token, spam[i]) == 0) {
                count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char spam[][MAX_SPAM_LENGTH] = {"buy", "viagra", "earn", "money", "inheritance"};
    int num_spam = 5;
    char message[MAX_MSG_LENGTH];

    printf("Enter your message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);

    int spam_count = check_spam(message, spam, num_spam);

    if (spam_count > 0)
        printf("Your message has %d spam words. Please revise your message.\n", spam_count);
    else
        printf("Your message is not spam. It has been sent successfully.\n");

    return 0;
}