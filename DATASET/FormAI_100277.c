//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sender[50], recipient[50], subject[100], message[500];
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);

    // Creating a file to store the email
    FILE *fp = fopen("email.txt", "w");

    // Error handling
    if(fp == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    // Writing email header to file
    fprintf(fp, "From: <%s>\n", sender);
    fprintf(fp, "To: <%s>\n", recipient);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message:\n%s", message);

    // Closing file
    fclose(fp);

    // Successful email send output
    printf("Email sent to %s\n", recipient);

    return 0;
}