//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAIL_SIZE 1024

void send_email(char *host, int port, char *from, char *to, char *subject, char *body) {
    printf("Connecting to %s:%d...\n", host, port);
    //TODO: Implement SMTP connection code here
    printf("Connected! Sending email...\n");
    //Send email header
    printf("From: %s\n", from);
    printf("To: %s\n", to);
    printf("Subject: %s\n", subject);
    //Send email body
    printf("%s", body);
    printf("\nEmail sent successfully!\n");
}

int main() {
    char email[MAX_EMAIL_SIZE];
    char *host = "mail.surreal.com";
    int port = 25;
    char *from = "alice@surreal.com";
    char *to = "bob@surreal.com";
    char *subject = "Surrealist SMTP Client Program";
    char *body = "Dear Bob,\n\nI am a surrealistic SMTP client program, and I am sending you this email as a demonstration of my abilities.\n\nSincerely,\nAlice\n\nPS: Did you know that a giraffe can clean its ears with its 21 inch tongue?";

    //Create random email address
    srand(time(NULL));
    char random_str[10];
    sprintf(random_str, "%d", rand() % 10000);
    strcat(from, random_str);
    strcat(to, random_str);

    //Build email message
    sprintf(email, "From: %s\nTo: %s\nSubject: %s\n%s", from, to, subject, body);

    //Send email
    send_email(host, port, from, to, subject, body);

    return 0;
}