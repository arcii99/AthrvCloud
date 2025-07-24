//FormAI DATASET v1.0 Category: Email Client ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to send email
void send_email(char* to_email, char* subject, char* message){
    printf("\nTo: %s", to_email);
    printf("\nSubject: %s", subject);
    printf("\nMessage: %s\n", message);
}

int main(){
    char recipient[50], subject[100], message[500];
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter email subject: ");
    getchar(); // to clear the input buffer
    fgets(subject, 100, stdin);
    printf("Enter message: ");
    fgets(message, 500, stdin);

    // Removing the extra newline character from 'subject' and 'message'
    size_t ln = strlen(subject) - 1;
    if (subject[ln] == '\n')
        subject[ln] = '\0';

    ln = strlen(message) - 1;
    if (message[ln] == '\n')
        message[ln] = '\0';

    // Sending email
    send_email(recipient, subject, message);

    return 0;
}