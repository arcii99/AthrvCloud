//FormAI DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 50

// declaring function prototypes
void get_email_details(char *to, char *subject, char *message);
void send_email(char *to, char *subject, char *message);

int main() {
    char to[MAX_CHAR], subject[MAX_CHAR], message[MAX_CHAR*10];
    
    printf("Welcome to the C Email Client!\n\n");
    
    // get email details from the user
    get_email_details(to, subject, message);
    
    // send email
    send_email(to, subject, message);
    
    printf("\nEmail sent successfully!\n");
    
    return 0;
}

// Function to get email details from the user
void get_email_details(char *to, char *subject, char *message) {
    printf("Enter recipient email address: ");
    fgets(to, MAX_CHAR, stdin);
    to[strcspn(to, "\n")] = 0; // remove the newline character from the input
    
    printf("Enter email subject: ");
    fgets(subject, MAX_CHAR, stdin);
    subject[strcspn(subject, "\n")] = 0;
    
    printf("Enter email message (max 500 characters):\n");
    fgets(message, MAX_CHAR*10, stdin);
    message[strcspn(message, "\n")] = 0;
}

// Function to send email
void send_email(char *to, char *subject, char *message) {
    char command[MAX_CHAR*12]; // string variable to store the command to be executed
    
    sprintf(command, "echo \"%s\" | mail -s \"%s\" %s", message, subject, to); // constructing the command to be executed
    
    system(command); // execute the command
}