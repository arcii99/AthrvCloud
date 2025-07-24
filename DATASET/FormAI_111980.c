//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <string.h>

// function to check if a message is spam
int isSpam(char* message[]) {
    int i, count = 0;
    char spamWords[5][10] = {"buy", "cheap", "discount", "money", "free"};

    // loop through the message and count the occurrence of each spam word
    for(i = 0; i < strlen(message); i++) {
        for (int j = 0; j < 5; j++) {
            if (strstr(message[i], spamWords[j]) != NULL) {
                count++;
            }
        }
    }

    // if the count is greater than 3, then the message is spam
    if(count > 3) {
        return 1;
    }

    // otherwise, the message is not spam
    return 0;
}

int main() {
    int i, numMessages;
    char *messages[100];

    printf("Enter the number of messages: ");
    scanf("%d", &numMessages);

    // loop through all the messages and check if they are spam
    for (i = 0; i < numMessages; i++) {
        printf("Enter message %d: ", i + 1);
        scanf("%s", messages[i]);

        if (isSpam(messages[i])) {
            printf("Message %d is spam.\n", i + 1);
        } else {
            printf("Message %d is not spam.\n", i + 1);
        }
    }

    return 0;
}