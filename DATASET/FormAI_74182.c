//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to detect spam messages */
int spamDetection(char *message) {
    int count_uppercase = 0, count_lowercase = 0, count_digits = 0, count_special = 0;
    int i, message_len = strlen(message);

    /* Counting uppercase, lowercase, digits and special characters */
    for (i = 0; i < message_len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') count_uppercase++;
        else if (message[i] >= 'a' && message[i] <= 'z') count_lowercase++;
        else if (message[i] >= '0' && message[i] <= '9') count_digits++;
        else count_special++;
    }

    /* Checking for spam keywords */
    if (count_uppercase >= 10 && count_special >= 5) return 1;
    if (count_digits >= 6 && count_special >= 4) return 1;
    if (count_lowercase >= 20 && count_special >= 3) return 1;
    if (strstr(message, "click here") != NULL || strstr(message, "buy now") != NULL) return 1;
    if (strstr(message, "make money fast") != NULL || strstr(message, "cash prize") != NULL) return 1;

    /* Not detected as spam */
    return 0;
}

int main() {
    char message[200];

    /* Getting input message from user */
    printf("Enter the message: ");
    fgets(message, 200, stdin);
    
    /* Removing newline character from message */
    if (message[strlen(message)-1] == '\n') message[strlen(message)-1] = '\0';

    /* Checking if message is spam */
    if (spamDetection(message)) printf("SPAM DETECTED!\n");
    else printf("NOT A SPAM.\n");
    
    return 0;
}