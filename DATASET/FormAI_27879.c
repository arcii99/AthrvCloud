//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char message[101];
    int uppercase = 0;
    int symbols = 0;
    int numbers = 0;
    int spam = 0;

    printf("Enter your message: ");
    fgets(message, 101, stdin);

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            uppercase++;
        } else if ((message[i] >= '!' && message[i] <= '/') || 
                   (message[i] >= ':' && message[i] <= '@') ||
                   (message[i] >= '[' && message[i] <= '`') ||
                   (message[i] >= '{' && message[i] <= '~')) {
            symbols++;
        } else if (message[i] >= '0' && message[i] <= '9') {
            numbers++;
        } else {
            continue;
        }
    }

    if (symbols >= 5 && (uppercase >= 3 || numbers >= 3)) {
        spam = 1;
    }

    if (spam) {
        printf("SPAM DETECTED.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}