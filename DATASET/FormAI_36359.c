//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the email message
#define MAX_MSG_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_RECIPIENTS 10

// Define the email struct
typedef struct email
{
    char to[MAX_RECIPIENTS][50];
    char from[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MSG_LENGTH];
} Email;

// Function to send email
void send_email(Email *email)
{
    printf("Email Sent!\nTo: %s\nFrom: %s\nSubject: %s\nMessage: %s\n",
           email->to[0], email->from, email->subject, email->message);
}

int main()
{
    Email my_email;
    strcpy(my_email.to[0], "example@gmail.com");
    strcpy(my_email.from, "myemail@gmail.com");
    strcpy(my_email.subject, "Hello World!");
    strcpy(my_email.message, "This is my first email sent through C programming language");

    send_email(&my_email);

    return 0;
}