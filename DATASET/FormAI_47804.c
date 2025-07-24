//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT 100
#define MAX_MESSAGE 500

void send_email(char *to, char *subject, char *message) {
    FILE *fp;

    fp = fopen("sent_emails.txt", "a");
    fprintf(fp, "To: %s\nSubject: %s\n\n%s\n", to, subject, message);
    fclose(fp);
}

int main() {
    char to[50], subject[MAX_SUBJECT], message[MAX_MESSAGE];

    printf("Welcome to GratefulMail!\n\n");
    printf("Who would you like to send an email to? ");
    scanf("%s", to);

    printf("What is the subject of your email? ");
    fgets(subject, MAX_SUBJECT, stdin);

    printf("Please write your message below:\n");
     fgets(message, MAX_MESSAGE, stdin);

    send_email(to, subject, message);

    printf("\nYour email has been sent! Thank you for using GratefulMail.\n");

    return 0;
}