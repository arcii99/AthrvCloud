//FormAI DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Sherlock Holmes Email Client! \n\n");
    
    char subject[100];
    char sender[100];
    char message[1000];
    char recipient[100];
    
    printf("Enter the recipient's email: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0;
    
    printf("Enter the sender's email: ");
    fgets(sender, sizeof(sender), stdin);
    sender[strcspn(sender, "\n")] = 0;
    
    printf("Enter the email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0;
    
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;
    
    printf("\n\nThe email has been sent! It reads as follows: \n\n");
    printf("To: %s \n", recipient);
    printf("From: %s \n", sender);
    printf("Subject: %s \n", subject);
    printf("%s \n", message);
    
    return 0;
}