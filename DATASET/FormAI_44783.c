//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char message[500];
    int i, count = 0;

    printf("Enter your message: ");
    scanf("%[^\n]", message);

    // Remove any punctuation marks
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] == ',' || message[i] == '.' || message[i] == '!' || message[i] == '?') {
            memmove(&message[i], &message[i+1], strlen(message)-i);
        }
    }

    // Count the number of spam words
    char spamWords[10][20] = {"buy", "spam", "money", "free", "deal", "winner", "offer", "discount", "cash", "limited"};
    char *token = strtok(message, " ");
    while(token != NULL) {
        for(i = 0; i < 10; i++) {
            if(strcmp(token, spamWords[i]) == 0) {
                count++;
            }
        }
        token = strtok(NULL, " ");
    }

    // Determine if message is spam or not
    if(count >= 3) {
        printf("\nSPAM ALERT: This message contains %d spam words!\n", count);
    } else {
        printf("\nThis message is not spam.\n");
    }

    return 0;
}