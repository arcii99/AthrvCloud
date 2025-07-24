//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX 100

/* Constructing the email structure */
typedef struct {
    char subject[MAX];
    char body[MAX];
    char recipient[MAX];
} email;

/* Function to get email inputs */
email getEmail() {
    email mail;
    printf("Enter the recipient:");
    fgets(mail.recipient, MAX, stdin);
    
    printf("Enter subject:");
    fgets(mail.subject, MAX, stdin);
    
    printf("Enter the body of the email:");
    fgets(mail.body, MAX, stdin);
    
    return mail;
}

/* Function to send the email */
void sendEmail(email mail) {
    printf("Email sent to: %s\nSubject: %sBody: %s", mail.recipient, mail.subject, mail.body);
}

/* Main function */
int main() {
    email mail = getEmail();
    sendEmail(mail);
    
    return 0;
}