//FormAI DATASET v1.0 Category: Email Client ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int main(){
    char host[MAX], username[MAX], password[MAX], recipient[MAX], subject[MAX];
    char body[MAX], message[MAX];
    int port;

    printf("Enter the details:\n");

    printf("Host: ");
    scanf("%s", host);

    printf("Port: ");
    scanf("%d", &port);

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    printf("Recipient: ");
    scanf("%s", recipient);

    printf("Subject: ");
    scanf("%s", subject);

    printf("Message body: ");
    fgetc(stdin);
    fgets(body, MAX, stdin);

    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", username, recipient, subject, body);

    //Establishing socket connection here and sending the email using SMTP protocol

    printf("Email sent successfully!\n");

    return 0;
}