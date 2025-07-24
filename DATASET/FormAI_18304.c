//FormAI DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// define some constants for easy modification
#define SPAM_THRESHOLD 3
#define MAX_MESSAGES 100

int spamCount = 0;
char messages[MAX_MESSAGES][100] = {"Hello there!", "How are you?", "I love coding!", "Make money fast!", "Click this link!", "You have won a prize!", "Act now!", "Limited time offer!", "$$$"};

// function for checking if a message contains spam words
int containsSpam(char* message) {
    char* spamWords[] = {"money", "fast", "prize", "click", "offer", "$$$"};
    int numSpamWords = sizeof(spamWords) / sizeof(char*);
    for (int i = 0; i < numSpamWords; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < MAX_MESSAGES; i++) {
        char message[100];
        printf("Enter message #%d: ", i+1);
        fgets(message, 100, stdin);
        // remove newline character from input
        message[strcspn(message, "\n")] = 0;
        if (containsSpam(message)) {
            printf("This message contains spam!\n");
            spamCount++;
        }
        messages[i][0] = '\0';
        strcat(messages[i], message);
        if (i >= SPAM_THRESHOLD) {
            if (containsSpam(messages[i - SPAM_THRESHOLD])) {
                printf("Previous message detected as spam!\n");
                spamCount--;
            }
        }
        printf("\n");
        if (spamCount >= SPAM_THRESHOLD) {
            printf("SPAM THRESHOLD REACHED! SENDING ALERT!\n");
            // code for sending alert would go here
            return 0;
        }
    }
    printf("End of program.\n");
    return 0;
}