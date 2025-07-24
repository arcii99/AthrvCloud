//FormAI DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char receiver_email[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void send_email(Email *email) {
    printf("To: %s\n", email->receiver_email);
    printf("Subject: %s\n", email->subject);
    printf("%s\n", email->body);
}

int main() {
    Email my_email;
    printf("Enter receiver email:\n");
    scanf("%s", my_email.receiver_email);
    printf("Enter email subject:\n");
    scanf("%s", my_email.subject);
    printf("Enter email body:\n");
    scanf("%[^\n]s", my_email.body);
    send_email(&my_email);
    return 0;
}