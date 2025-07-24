//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int spamCount = 0;

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    for(int i = 0; i < strlen(message); i++) {
        if(message[i] == '$') {
            spamCount++;
        }
    }

    if(spamCount >= 3) {
        printf("ALERT: SPAM DETECTED\n");
        // Code to report spam to authorities
        // Code to ban user
    } else {
        printf("Message OKAY to send\n");
    }

    return 0;
}