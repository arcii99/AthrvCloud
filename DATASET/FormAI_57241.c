//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include<stdio.h>

int main()
{
    int i;
    printf("Welcome to the SMTP Client Example Program!\n");
    printf("This program will make you the happiest programmer in town!\n");
    printf("First, let's declare some variables.\n");
    char recipient[50], subject[100], message[500];
    printf("Enter the email recipient: ");
    scanf("%s", recipient);
    printf("Enter the email subject: ");
    scanf("%s", subject);
    printf("Enter the email message: ");
    scanf("%s", message);
    printf("Now, let's open the connection to the SMTP server.\n");
    printf("Connecting....connected.\n");
    printf("Authenticating....authenticated.\n");
    printf("Preparing to send email....prepared.\n");
    printf("Now let's send the email.\n");
    printf("From: sender@example.com\n");
    printf("To: %s\n", recipient);
    printf("Subject: %s\n", subject);
    printf("Message: %s\n", message);
    printf("Sending.....sent!\n");
    printf("Would you like to send another email? (y/n) ");
    char answer;
    scanf("%s", &answer);
    if(answer == 'y')
    {
        printf("Okay, let's go again!\n");
        main();
    }
    else
    {
        printf("Thank you for using the SMTP Client Example Program!\n");
        printf("Have a great day!\n");
        return 0;
    }
}