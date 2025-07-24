//FormAI DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char message[500];
    printf("Enter a message for spam detection: ");
    fgets(message, sizeof(message), stdin);

    // Convert all uppercase letters to lowercase letters
    for(int i = 0; i < strlen(message); i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += 32;
        }
    }

    // Check for common spam words
    int flag = 0;
    const char *spamWords[] = {"buy", "discount", "sale", "limited time offer", "money back guarantee", "win"};
    for(int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if(strstr(message, spamWords[i]) != NULL) {
            flag = 1;
            break;
        }
    }

    // Determine if the message is spam or not
    if(flag == 1) {
        printf("This message may be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}