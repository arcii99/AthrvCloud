//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <string.h>

// Function to check if the given string contains spam words
int isSpam(char *str)
{
    char *spamWords[] = {"buy now", "limited time", "discount", "click here"};

    int i;
    for (i = 0; i < 4; i++) {
        if (strstr(str, spamWords[i])) {
            return 1; // If a spam word is found, return 1
        }
    }
    return 0; // If no spam word is found, return 0
}

int main()
{
    char message[1000];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    // Remove the newline character from the end of the string
    message[strcspn(message, "\n")] = 0;

    // Check if the message contains spam words
    int spam = isSpam(message);

    if (spam) {
        printf("Your message contains spam words.\n");
    } else {
        printf("Your message has been sent.\n");
    }

    return 0;
}