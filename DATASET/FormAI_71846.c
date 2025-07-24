//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>

#define MAX_SUBJECT_SIZE 50
#define MAX_BODY_SIZE 200

void send_email(char *to, char *subject, char *body);

int main()
{
    char to[50], subject[MAX_SUBJECT_SIZE], body[MAX_BODY_SIZE];
    
    printf("Welcome to your email client!\n");
    printf("Who would you like to send an email to?\n");
    scanf("%s", to);
    
    printf("What is the subject of your email? (Max 50 characters)\n");
    scanf("%s", subject);
    
    printf("What would you like to say? (Max 200 characters)\n");
    scanf("%s", body);
    
    send_email(to, subject, body);
    
    printf("\nYour email has been sent!\n");
    
    return 0;
}

void send_email(char *to, char *subject, char *body)
{
    // Code to send email
    printf("\nEmail sent to %s with the subject \"%s\" and message \"%s\"\n", to, subject, body);
}