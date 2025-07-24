//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Email client example program */
int main()
{
    char to[50], subject[100], body[500], sent[200];
    int i;

    printf("Welcome to minimalist C email client!\n\n");

    printf("To: ");
    fgets(to, 50, stdin);

    printf("Subject: ");
    fgets(subject, 100, stdin);

    printf("Body: ");
    fgets(body, 500, stdin);

    /* Remove newline from input */
    i = strlen(to);
    if (to[i-1] == '\n') {
        to[i-1] = '\0';
    }

    i = strlen(subject);
    if (subject[i-1] == '\n') {
        subject[i-1] = '\0';
    }

    i = strlen(body);
    if (body[i-1] == '\n') {
        body[i-1] = '\0';
    }

    /* Compose email */
    sprintf(sent, "To: %s\nSubject: %s\n%s", to, subject, body);

    printf("\nEmail ready to send:\n%s", sent);

    printf("Your email has been successfully sent!\n");

    return 0;
}