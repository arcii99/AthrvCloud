//FormAI DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAIL_PREAMBLE 1024
#define MAX_EMAIL_BODY 10240
#define MAX_NAME_LEN 256
#define MAX_EMAIL_SUBJECT 1024
#define MAX_EMAIL_ADDR_LEN 1024

void compose_email(char *email_to, char *email_subject, char *email_body) {
    char email_preamble[MAX_EMAIL_PREAMBLE];
    char name[MAX_NAME_LEN];
    snprintf(name, MAX_NAME_LEN, "Ken Thompson");

    snprintf(email_preamble, MAX_EMAIL_PREAMBLE, "To: %s\nFrom: %s <%s>\nSubject: %s\n\n", email_to, name, "kthomp@bell-labs.com", email_subject);

    printf("%s%s", email_preamble, email_body);
}

int main(void) {
    char email_to[MAX_EMAIL_ADDR_LEN];
    char email_subject[MAX_EMAIL_SUBJECT];
    char email_body[MAX_EMAIL_BODY];

    printf("Enter email recipient: ");
    fgets(email_to, MAX_EMAIL_ADDR_LEN, stdin);
    email_to[strcspn(email_to, "\n")] = '\0';

    printf("Enter email subject: ");
    fgets(email_subject, MAX_EMAIL_SUBJECT, stdin);
    email_subject[strcspn(email_subject, "\n")] = '\0';

    printf("Enter email body: ");
    fgets(email_body, MAX_EMAIL_BODY, stdin);
    email_body[strcspn(email_body, "\n")] = '\0';

    compose_email(email_to, email_subject, email_body);

    return 0;
}