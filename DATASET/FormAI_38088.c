//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000];
    int spam_count = 0;

    printf("Enter the message to check for spam: ");
    fgets(message, 1000, stdin);

    // List of spam phrases
    char *spam_list[] = {"free money", "get rich quick", "call now", "limited time offer", "act now"};

    // Check if message contains spam phrases
    for (int i = 0; i < sizeof(spam_list)/sizeof(spam_list[0]); i++) {
        if (strstr(message, spam_list[i]) != NULL) {
            spam_count++;
        }
    }

    // Check if message is all caps
    int all_caps = 1;
    for (int i = 0; i < strlen(message) - 1; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            all_caps = 0;
            break;
        }
    }

    // Check if message has too many exclamation points
    int exclamation_count = 0;
    for (int i = 0; i < strlen(message) - 1; i++) {
        if (message[i] == '!') {
            exclamation_count++;
        }
    }

    // Check if message is longer than 160 characters
    int length = strlen(message) - 1;
    if (length > 160) {
        printf("This message is longer than 160 characters and may be considered spam.\n");
        spam_count++;
    }

    // Determine if message is spam
    if (spam_count >= 2 || all_caps == 1 || exclamation_count >= 4) {
        printf("This message seems to be spam!\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}