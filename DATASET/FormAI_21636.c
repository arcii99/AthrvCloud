//FormAI DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define SPAM_LIMIT 3

int main()
{
    char message[100];
    int spam_count = 0;

    printf("Welcome to the Spam Detection System!\n");
    printf("Enter your message:\n");

    // read user input
    fgets(message, sizeof(message), stdin);

    // check for spam keywords
    if (strstr(message, "make money fast") != NULL) {
        spam_count++;
    }

    if (strstr(message, "buy now") != NULL) {
        spam_count++;
    }

    if (strstr(message, "act now") != NULL) {
        spam_count++;
    }

    // determine if message is spam
    if (spam_count >= SPAM_LIMIT) {
        printf("SPAM DETECTED!\n");

        // send warning email to admin
        system("echo 'Spam Detected!' | mailx -s 'Spam Alert' admin@yourdomain.com");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}