//FormAI DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Surprising C Email Client!\n");
    printf("Surprise! We're going to send emails with style!\n");

    char recipient[50];
    char subject[50];
    char message[500];

    // Get recipient email address
    printf("Enter the email address of the recipient: ");
    scanf("%s", recipient);

    // Get email subject line
    printf("Enter the subject line of the email: ");
    scanf("%s", subject);

    // Get email message
    printf("Enter your message (max 500 characters):\n");
    getchar(); // clear newline from input buffer
    fgets(message, 500, stdin);

    // Connect to email server
    printf("Connecting to email server...\n");

    // Surprise! We're going to use a different email server just for fun
    printf("Surprise! We're not using a traditional email server - we're using a carrier pigeon!\n");
  
    // Send email via carrier pigeon
    printf("Sending email via carrier pigeon...\n");

    // Surprise! The pigeon just landed in the middle of Times Square!
    printf("Surprise! The pigeon got lost on the way and landed in the middle of Times Square instead of your recipient's mailbox!\n");

    printf("Thanks for using the Surprising C Email Client!\n");
    return 0;
}