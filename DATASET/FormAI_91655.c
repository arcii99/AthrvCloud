//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char body[500];
};

void sendEmail(struct email *e) {
    printf("\nSending email...\n");
    printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n", e->sender, e->receiver, e->subject, e->body);
    printf("Email sent!\n");
}

int main() {
    struct email *myEmail = malloc(sizeof(struct email));
    if (myEmail == NULL) {
        printf("Error allocating memory for email.\n");
        return 1;
    }

    printf("Enter sender email address: ");
    fgets(myEmail->sender, 50, stdin);
    myEmail->sender[strcspn(myEmail->sender, "\n")] = '\0';

    printf("Enter receiver email address: ");
    fgets(myEmail->receiver, 50, stdin);
    myEmail->receiver[strcspn(myEmail->receiver, "\n")] = '\0';

    printf("Enter email subject: ");
    fgets(myEmail->subject, 100, stdin);
    myEmail->subject[strcspn(myEmail->subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(myEmail->body, 500, stdin);
    myEmail->body[strcspn(myEmail->body, "\n")] = '\0';

    sendEmail(myEmail);

    free(myEmail);
    return 0;
}