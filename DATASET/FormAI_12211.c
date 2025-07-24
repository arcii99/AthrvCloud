//FormAI DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold the email information
typedef struct{
    char sender[100];
    char recipient[100];
    char subject[100];
    char body[1000];
} Email;

// function to display the email information
void displayEmail(Email email){
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

int main(){
    // create an Email object
    Email email1;
    
    // set the email information
    strcpy(email1.sender, "john_doe@gmail.com");
    strcpy(email1.recipient, "jane_doe@yahoo.com");
    strcpy(email1.subject, "Test Email");
    strcpy(email1.body, "Hello Jane,\n\nThis is a test email. Please let me know if you received it.\n\nThanks,\nJohn");
    
    // display the email information
    displayEmail(email1);
    
    return 0;
}