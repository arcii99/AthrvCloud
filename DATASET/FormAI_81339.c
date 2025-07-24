//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char username[50];
    char password[50];
    char recipient[50];
    char subject[100];
    char message[1000];

    printf("\n\tWelcome to the Surrealist Email Client!\n");
    printf("\nPlease enter your email address: ");
    scanf("%s", username);
    printf("\nPlease enter your password: ");
    scanf("%s", password);

    printf("\nEnter recipient's email address: ");
    scanf("%s", recipient);
    printf("\nEnter subject: ");
    scanf("%s", subject);
    printf("\nEnter message: ");
    scanf("%s", message);

    printf("\n\nHacking into the system...\n");
    printf("Decrypting firewalls...\n");
    printf("Finding the email server...\n");
    printf("Opening the portal to the digital realm...\n");

    printf("\nMessage sent to %s!", recipient);

    return 0;
}