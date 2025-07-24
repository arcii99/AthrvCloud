//FormAI DATASET v1.0 Category: Email Client ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char to[30], subject[50], message[100], sender[30];
    printf("Enter the sender's email address:\n");
    scanf("%s", sender);
    printf("Enter the receiver's email address:\n");
    scanf("%s", to);
    printf("Enter the subject:\n");
    scanf("%s", subject);
    printf("Enter the message:\n");
    scanf("%s", message);
    strcat(message, "\n\nSent from my email client");

    FILE *fp;
    fp = fopen("email.txt", "w");

    fprintf(fp, "From: %s\n", sender);
    fprintf(fp, "To: %s\n", to);
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: \n%s", message);

    fclose(fp);
    printf("Email sent successfully!\n");
    return 0;
}