//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

struct email {
    char recipient[50];
    char sender[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
};

void send_email(struct email e) {
    printf("Sending email to: %s\n", e.recipient);
    printf("From: %s\n", e.sender);
    printf("Subject: %s\n", e.subject);
    printf("Body:\n%s\n", e.body);
}

int main() {
    struct email e;
    
    printf("Enter recipient: ");
    fgets(e.recipient, sizeof(e.recipient), stdin);
    e.recipient[strcspn(e.recipient, "\n")] = '\0';
    
    printf("Enter sender: ");
    fgets(e.sender, sizeof(e.sender), stdin);
    e.sender[strcspn(e.sender, "\n")] = '\0';
    
    printf("Enter subject: ");
    fgets(e.subject, sizeof(e.subject), stdin);
    e.subject[strcspn(e.subject, "\n")] = '\0';
    
    printf("Enter body: ");
    fgets(e.body, sizeof(e.body), stdin);
    e.body[strcspn(e.body, "\n")] = '\0';
    
    send_email(e);
    
    return 0;
}