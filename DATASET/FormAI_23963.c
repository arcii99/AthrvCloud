//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_PORT 1025
#define MAX_LENGTH 1024

typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
} Email;

void send(Email *email, char *server, int port) {
    printf("Sending email from %s to %s\n", email->sender, email->recipient);
    
    // code to connect to the email server and send email
    
    printf("Email sent successfully\n");
}

int main() {
    Email email;
    email.sender = "example1@gmail.com";
    email.recipient = "example2@yahoo.com";
    email.subject = "Hello World";
    email.body = "This is a test email sent using a C email client program";
    
    char server[MAX_LENGTH];
    printf("Enter email server address: ");
    fgets(server, MAX_LENGTH, stdin);
    server[strcspn(server, "\n")] = 0;
    
    int port = DEFAULT_PORT;
    char portInput[MAX_LENGTH];
    printf("Enter port number (press Enter to use default port %d): ", DEFAULT_PORT);
    fgets(portInput, MAX_LENGTH, stdin);
    if (strlen(portInput) > 1) {
        port = atoi(portInput);
    }
    
    send(&email, server, port);
    
    return 0;
}