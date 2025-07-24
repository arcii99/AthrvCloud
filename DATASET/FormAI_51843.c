//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 1000
#define MAX_MESSAGE_LENGTH 100

int main() {
    char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
    int i, j, k, count;

    // Accept messages from user
    for (i = 0; i < MAX_MESSAGES; i++) {
        printf("Enter message %d: ", i+1);
        fgets(messages[i], MAX_MESSAGE_LENGTH, stdin);
        // Remove newline character at end of message
        messages[i][strcspn(messages[i], "\n")] = 0;
        // If user enters "DONE", stop accepting messages
        if (strcmp(messages[i], "DONE") == 0) {
            break;
        }
    }

    // Check for spam messages
    count = 0;
    for (i = 0; i < MAX_MESSAGES; i++) {
        // Check for excessive use of exclamation marks
        if (strchr(messages[i], '!') != NULL) {
            k = 0;
            for (j = 0; j < strlen(messages[i]); j++) {
                if (messages[i][j] == '!') {
                    k++;
                }
            }
            if (k > 3) {
                printf("Warning: Message %d may be spam (excessive use of exclamation marks)\n", i+1);
                count++;
            }
        }
        // Check for repeated letters
        if (strstr(messages[i], "lll") != NULL || strstr(messages[i], "ooo") != NULL) {
            printf("Warning: Message %d may be spam (repeated letters)\n", i+1);
            count++;
        }
        // Check for excessive capitalization
        k = 0;
        for (j = 0; j < strlen(messages[i]); j++) {
            if (messages[i][j] >= 'A' && messages[i][j] <= 'Z') {
                k++;
            }
        }
        if (k > strlen(messages[i])/2) {
            printf("Warning: Message %d may be spam (excessive capitalization)\n", i+1);
            count++;
        }
    }

    printf("Total number of spam messages detected: %d\n", count);

    return 0;
}