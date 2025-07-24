//FormAI DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_SUBJECT_LENGTH 100
#define MAX_SENDER_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

/* Define the email structure */
typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char date[MAX_DATE_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

/* Define the email client structure */
typedef struct {
    Email emails[MAX_EMAILS];
    int num_emails;
} Email_Client;

/* Function to add an email to the email client */
void add_email(Email_Client *client, char subject[MAX_SUBJECT_LENGTH], char sender[MAX_SENDER_LENGTH], char date[MAX_DATE_LENGTH], char body[MAX_BODY_LENGTH]) {
    Email email;
    strcpy(email.subject, subject);
    strcpy(email.sender, sender);
    strcpy(email.date, date);
    strcpy(email.body, body);
    client->emails[client->num_emails] = email;
    client->num_emails++;
}

int main() {
    /* Initialize the email client */
    Email_Client client;
    client.num_emails = 0;
    
    /* Create some example emails */
    add_email(&client, "Hello", "johndoe@gmail.com", "2022-01-01", "Hi there!");
    add_email(&client, "Reminder", "janedoe@yahoo.com", "2022-01-02", "Don't forget the meeting tomorrow.");
    add_email(&client, "Important", "bobsmith@hotmail.com", "2022-01-03", "Please review the attached document.");
    
    /* Print out all the emails in the client */
    printf("There are %d emails in the client:\n", client.num_emails);
    for (int i = 0; i < client.num_emails; i++) {
        printf("Subject: %s\n", client.emails[i].subject);
        printf("From: %s\n", client.emails[i].sender);
        printf("Date: %s\n", client.emails[i].date);
        printf("Body: %s\n", client.emails[i].body);
        printf("\n");
    }
    
    /* Exit the program successfully */
    return 0;
}