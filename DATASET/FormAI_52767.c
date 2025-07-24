//FormAI DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 10
#define HAM_THRESHOLD 15

int main() {
    char input[1000];
    int spam_count = 0;
    int ham_count = 0;

    printf("Welcome to my Spam Detection System, please enter your message:\n");

    fgets(input, 1000, stdin);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 's') {
            spam_count++;
        } else if (input[i] == 'h') {
            ham_count++;
        }
    }

    if (spam_count > SPAM_THRESHOLD) {
        printf("SPAM DETECTED! Message rejected.\n");
        return 0;
    } else if (ham_count > HAM_THRESHOLD) {
        printf("Possible HAM detected. Message under review.\n");
        return 0;
    } else {
        printf("Message successfully sent.\n");
        return 0;
    }
}