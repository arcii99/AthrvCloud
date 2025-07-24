//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[1000];
    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    int i, j, k, flag;
    char* spamWords[8] = {"buy", "discount", "free", "money back", "limited time offer", "work from home", "earn money fast", "make money online"};

    for (i = 0; i < strlen(message); i++) {
        flag = 1;
        for (j = 0; j < 8; j++) {
            if (strncmp(&message[i], spamWords[j], strlen(spamWords[j])) == 0) {
                for (k = i; k < i + strlen(spamWords[j]); k++) {
                    message[k] = '*';
                }
                flag = 0;
                break;
            }
        }
        if (!flag) {
            i = i + strlen(spamWords[j]) - 1;
        }
    }

    printf("Filtered message: %s", message);
    return 0;
}